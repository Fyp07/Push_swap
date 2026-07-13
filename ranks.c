
#include "push_swap.h"

t_list	*set_bucket_ranks(t_list **stack, int total_size)
{
	t_list	*current;
	t_list	*compare;
	t_list	*head;
	int		buckets;
	int		rank_index;

	head = *stack;
	total_size = ft_lstsize(head);
	buckets = ft_sqrt(total_size);
	current = head;
	while (current)
	{
		compare = (*stack)->next;
		rank_index = 0;
		while (compare)
		{
			if (current->value > compare->value)
				rank_index++;
			compare = compare->next;
		}
		current->rank = rank_index / buckets;
		current = current->next;
	}
	return (head);
}

int	number_of_ranks(t_list *list)
{
	int	max;

	max = 0;
	while (list)
	{
		if (list->rank > max)
			max = list->rank;
		list = list->next;
	}
	return (max);
}

int	has_rank(t_list *list, int rank)
{
	while (list)
	{
		if (list->rank == rank)
			return (1);
		list = list->next;
	}
	return (0);
}

int	find_rank_pos(t_list *list, int rank)
{
	int	pos;

	pos = 0;
	while (list)
	{
		if (list->rank == rank)
		   return (pos);
		list = list->next;
		pos++;
	}
	return (0);
}
