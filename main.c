/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garodri2 <garodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 17:06:54 by fbarrada          #+#    #+#             */
/*   Updated: 2026/07/10 16:21:04 by garodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **argv) // Da free em tudo;
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

int	soma_movimentos(t_count *count) // TEMPORARIO
{
	int	total;

	total = count->pa + count->pb + count->ra + count->rb + count->rr
		+ count->rra + count->rrb + count->rrr + count->sa + count->sb;
	ft_printf("Total de movimentos: %d\n", total);
	return (total); 
}

int main(int argc, char **argv)
{
	t_input input;
	static t_count	count;
	t_list *stack_a;
	t_list *stack_b;
	char **str;
	
	stack_b = NULL;
	if (argc < 2)
		return (0);
	str = argv_to_string(argc - 1, argv + 1); // Faz o seguinte: 1 2 "3 4 5" 6 7; -> 1 2 3 4 5 6 7;
	if (processing_args(str, &input)) // Verifica se os argumentos sao validos
		return (write(2, "Error\n", 6), free_split(str), 1); // Se houver um erro, retorna uma mensagem de erro, da free em tudo e retorna 1);
	stack_a = create_stack(str, input.start, &input, &count); // Cria a stack;
	if (!stack_a)
		return(write(2, "Error\n", 6), free_split(str), 1);
	if (is_sorted(&stack_a))
	{
		// ft_printf("IS SORTED\n");
		// print_stack(stack_a, "A");
		return (0);
	}
	//chunk_sort(&stack_a, &stack_b, &count, &input);
	// soma_movimentos(&count);
	//print_stack_a_b(stack_a, stack_b);
	//set_bucket_ranks(&stack_a, count.size_a, COMPLEX);
	//print_ranks(stack_a);
	//print_stack_a_b(stack_a, stack_b);
	// simple_insertion(&stack_a, &stack_b, &count);
	complex_radix(&stack_a, &stack_b,&count);
	
	return (free_split(str), free_stack(&stack_a), 0);
}