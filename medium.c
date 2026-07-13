
#include "push_swap.h"

int	medium_search_cheapest(t_list *stack_a, t_list *stack_b, int rank)
{
	t_list	*copy_stack_a;
	int		best_postion;
	int		min_cost;
	int		position;
	int		cost;

	copy_stack_a = stack_a;
	min_cost = INT_MAX;
	position = 0;
	best_postion = 0;
	while (copy_stack_a)
	{
		if (copy_stack_a->rank == rank)
		{
			cost = cost_to_insert(stack_b, copy_stack_a->value, position,
					ft_lstsize(stack_a));
			if (cost < min_cost)
			{
				min_cost = cost;
				best_postion = position;
			}
		}
		copy_stack_a = copy_stack_a->next;
		position++;
	}
	return (best_postion);
}

void	medium_insertion(t_list **stack_a, t_list **stack_b, int rank,
		t_count *count)
{
	int	position_to_insert;
	int	best_element_a;

	while (has_rank(*stack_a, rank))
	{
		best_element_a = medium_search_cheapest(*stack_a, *stack_b, rank);
		rotation_a(stack_a, count, best_element_a);
		position_to_insert = find_nearest(stack_b, (*stack_a)->value);
		rotation_b(stack_b, count, position_to_insert);
		pb(stack_b, stack_a, count);
	}
}

void	go_max(t_list **stack_b, t_count *count)
{
	int	pos;
	int	size;
	int	i;

	pos = index_max(*stack_b);
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
