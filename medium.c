
#include "push_swap.h"

int	medium_find_cheapest(t_list *stack_a, t_list *stack_b, int rank)
{
	t_list	*node;
	int		best_pos;
	int		min_cost;
	int		pos;
	int		cost;

	node = stack_a;
	min_cost = INT_MAX;
	best_pos = 0;
	pos = 0;
	while (node)
	{
		if (node->rank == rank
			&& (cost = cost_to_insert(stack_b, node->value,
					pos, ft_lstsize(stack_a))) < min_cost)
			min_cost = cost, best_pos = pos;
		node = node->next;
		pos++;
	}
	return (best_pos);
}

void	medium_insertion(t_list **stack_a, t_list **stack_b, int rank,
		t_count *count)
{
	int	position_to_insert;
	int	best_element_a;

	while (has_rank(*stack_a, rank))
	{
		best_element_a = medium_find_cheapest(*stack_a, *stack_b, rank);
		rotation_a(stack_a, count, best_element_a);
		position_to_insert = nearest_position(*stack_b, (*stack_a)->value);
		rotation_b(stack_b, count, position_to_insert);
		pb(stack_b, stack_a, count);
	}
}

void	go_max(t_list **stack_b, t_count *count)
{
	int	pos;
	int	size;
	int	i;

	pos = max_position(stack_b);
	size = ft_lstsize(*stack_b);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(stack_b, count);
	}
	else
	{
		i = size - pos;
		while (i-- > 0)
			rrb(stack_b, count);
	}
}

void	medium_sort(t_list **stack_a, t_list **stack_b, t_count *count)
{
	int	rank;
	int	max_rank;
	int	total;
	int	chunk_size;

	if (count->size_a <= 2)
		return (sort_two(stack_a, count));
	else if (count->size_a <= 5)
		return (sort_five(stack_a, stack_b, count));
	total = 0;
	chunk_size = 0;
	*stack_a = set_bucket_ranks(stack_a, total);
	rank = 0;
	max_rank = number_of_ranks(*stack_a);
	while (rank <= max_rank)
	{
		medium_insertion(stack_a, stack_b, rank, count);
		rank++;
	}
	while ((*stack_b))
	{
		go_min(stack_b, count);
		pa(stack_a, stack_b, count);
	}
}

int	ft_sqrt(int num)
{
	int	i;

	i = 0;
	while (i * i <= num)
	{
		if (i * i == num)
			return (i);
		i++;
	}
	return (i - 1);
}
