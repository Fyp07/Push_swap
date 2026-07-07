
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

int	has_rank(t_list *list, int	rank)
{
	while (list)
	{
		if (list->rank == rank)
			return (1);
		list = list->next;
	}
	return (0);
}

int	find_next_rank(t_list *list, int rank)
{
	int	pos;

	pos = 0;
	while (list)
	{
		if (list->rank == rank)
		{
			ft_printf("Rank: %d\n", list->rank);
			return (pos);
		}
		list = list->next;
		pos++;
	}
	return (0);
}

void	search_ranks(t_list **a, t_list **b, t_count *count)
{
	int	pos;
	int	i;
	int rank;        // Onde comeca os ranks
	int quantity; // Numero de ranks

	quantity = number_of_ranks(*a);
	rank = 0;
	while (rank <= quantity) // 0 <= 2 -> 1 == 0 // 21 -> 3 -> 45 -> 1
	{
		while (has_rank(*a, rank))
		{
			pos = find_next_rank(*a, rank);
			if (pos <= count->size_a / 2)
			{
				while (pos-- > 0)
					ra(a, count);
				pb(b, a, count);
			}
			else
			{
				i = count->size_a - pos;
				while (i-- > 0)
					rra(a, count);
				pb(b, a, count);
			}
		}
		rank++;
	}
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