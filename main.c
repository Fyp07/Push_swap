/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 17:06:54 by fbarrada          #+#    #+#             */
/*   Updated: 2026/06/22 14:23:34 by fbarrada         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	t_input input;
	t_list *stack_a;
	char **str;
	int	i;
	
	i = 0;
	if (argc < 2)
		return (0);
	str = argv_to_string(argc - 1, argv + 1); // Faz o seguinte: 1 2 "3 4 5" 6 7; -> 1 2 3 4 5 6 7;
	if (processing_args(str, &input)) // Verifica se os argumentos sao validos
		return (write(2, "Error\n", 6), free_split(str), 1); // Se houver um erro, retorna uma mensagem de erro, da free em tudo e retorna 1);
	stack_a = create_stack(str, input.start);
	if (!stack_a)
		return(write(2, "Error\n", 6), free_split(str), 1);
	print_stack(stack_a, "A");
	ft_printf("\n");
	ra(&stack_a);
	print_stack(stack_a, "A");
	return (free_split(str), 0);
}
