 
#include "push_swap.h"

void	disorder_check(t_list **stack_a, t_list	**stack_b, t_input *input, t_count *count)
{
	int	i;

	i = (int)(input->disorder * 10);
	if (i == 0)
		return ;
	if (i < 2)
		simple_insertion(stack_a, stack_b, count);
	else if (i < 5)
		chunk_insertion(stack_a, stack_b, (*stack_a)->rank, count);
}

void	strategy(t_list	**stack_a, t_list	**stack_b, t_input	*input, t_count	*count)
{	
	ft_printf("Disorder: %f\n", input->disorder);
	input->disorder = compute_disorder(stack_a);
	ft_printf("Disorder: %f\n", input->disorder);
	if (input->disorder != 0)
	{
		if (input->bench == 1)
			print_benchmark(input, count);
	}
	else if (input->strategy == ERROR)
		return ;
	else if (input->strategy == ADAPTIVE)
	{
		ft_printf("USANDO DISORDER CHECK...\n");
		disorder_check(stack_a, stack_b, input, count);
	}
	else if (input->strategy == SIMPLE)
	{
		ft_printf("USANDO SIMPLE_INSERTION\n");
		simple_insertion(stack_a, stack_b, count);
	}
	else if (input->strategy == MEDIUM)
	{
		ft_printf("USANDO CHUNK_INSERTION\n");
		chunk_sort(stack_a, stack_b, count, input);
	}
	if (input->bench == 1)
		print_benchmark(input, count);
}
