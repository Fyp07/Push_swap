
#include "push_swap.h"

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

void	print_ranks(t_list *stack)
{
	t_list *current;
	int bucket;
	int max_bucket;

	max_bucket = 0;
	current = stack;
	while (current)
	{
		if (current->rank > max_bucket)
			max_bucket = current->rank;
		current = current->next;
	}
	bucket = 0;
	while (bucket <= max_bucket)
	{
		printf("Bucket [%d]: ", bucket);
		current = stack;
		while (current)
		{
			if (current->rank == bucket)
				printf("%d ", current->value);
			current = current->next;
		}
		printf("\n");
		bucket++;
	}
}