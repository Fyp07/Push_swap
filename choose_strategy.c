 
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
	input->disorder = compute_disorder(stack_a);
	if (input->disorder == 0)
	{
		if (input->bench == 1)
			print_benchmark(input, count);
		return ;
	}
	else if (input->strategy == ERROR)
		return ;
	else if (input->strategy == ADAPTIVE)
		disorder_check(stack_a, stack_b, input, count);
	else if (input->strategy == SIMPLE)
		simple_insertion(stack_a, stack_b, count);
	else if (input->strategy == MEDIUM)
		chunk_sort(stack_a, stack_b, count);
	if (input->bench == 1)
		print_benchmark(input, count);
}
