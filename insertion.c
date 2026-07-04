
#include "push_swap.h"

void	sort(t_list	**stack_a, t_list **stack_b, t_count *count)
{
	t_list	*min;
	int	markdown;

	markdown = 0;
	pb(stack_b, stack_a, count);
	while ((*stack_a))
	{
		min = find_min(stack_b);
		if ((*stack_a)->value > (*stack_b)->value) // TOPO
            pb(stack_b, stack_a, count);
		else if ((*stack_a)->value < min->value)
		{
			pb(stack_b, stack_a, count);
			rb(stack_b, count);
		}
		else if ((*stack_a)->value < (*stack_b)->value && (*stack_b)->next) // MEIO
		{
			while ((*stack_a)->value < (*stack_b)->value && (*stack_b)->next)
			{
				rb(stack_b, count);
				markdown++;
			}
			pb(stack_b, stack_a, count);
			while (markdown != 0)
			{
				rrb(stack_b, count);
				markdown--;
			}
		}
		else
			pb(stack_b, stack_a, count);
	}
}

// IDEIA: Verificar se o topo de A e maior que o topo de B. Se nao for,
// manda o topo de b para o fundo e compara dnv. Quando for, faz pb e depois
// rotaciona tudo de novo para cima.