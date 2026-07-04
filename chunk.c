
#include "push_swap.h"

t_list	*set_bucket_ranks(t_list	*stack, int	total_size)
{
	t_list	*current;
	t_list	*compare;
	t_list	*head;
	int buckets;
	int	rank_index;

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

void	print_ranks(t_list *stack)
{
	t_list	*current;
	int		bucket;
	int		max_bucket;

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

// void	ft_print_array(int	*array, int n)
// {
// 	int	current;
	
// 	current = 0;
// 	while (current <= n)
// 	{
// 		ft_printf("[%d]", array[current]);
// 		if (current + 1 <= n)
// 			ft_printf(" - ");
// 		current++;
// 	}
// }


// void	bucket(int	*array, int	n)
// {
// 	int	current;
// 	int compare;
// 	int	rank;
// 	int menor;

// 	current = 0;
// 	compare = 1;
// 	menor = 0;
// 	rank = 0;
// 	n = sizeof(array);
// 	rank = ft_sqrt(n);
// 	while (array[compare])
// 	{
// 		if (array[current] > array[compare])
// 			menor++;
// 		compare++;
// 	}
// 	current = 0;
// 	ft_print_array(array, n);
// 	ft_printf("\nELE E MAIOR QUE: %d numeros\n", menor);
// }

// int	main()
// {
// 	int array[] = {6, 1, 9, 3, 5, 10, 15, 32, 4};

// 	bucket(array, 9);
// 	return (0);
// }
// input->rank = 4 / 3; rank = 1; 