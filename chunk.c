
#include "push_swap.h"

t_list	*set_bucket_ranks(t_list *stack, int total_size)
{
	t_list	*current;
	t_list	*compare;
	t_list	*head;
	int		buckets;
	int		rank_index;

	head = stack;
	total_size = ft_lstsize(head);
	buckets = ft_sqrt(total_size);
	current = head;
	while (current)
	{
		compare = stack->next;
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
