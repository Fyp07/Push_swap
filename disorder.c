
#include "push_swap.h"

float compute_disorder(t_list **stack_a)
{
	float	mistakes;
	float	total_pairs;
	t_list	*walk;
	t_list	*next;

	mistakes = 0;
	total_pairs = 0;

	walk = *stack_a;
	while (walk)
	{
		next = walk->next;
		while (next)
		{
			total_pairs++;

			if (walk->value > next->value)
				mistakes++;
			next = next->next;
		}
		walk = walk->next;
	}
	return (mistakes / total_pairs);
}