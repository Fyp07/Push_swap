/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 17:06:54 by fbarrada          #+#    #+#             */
/*   Updated: 2026/07/13 15:27:16 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **argv)
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
	static t_count	count;
	t_list *stack_a;
	t_list *stack_b;
	char **str;
	
	stack_b = NULL;
	if (argc < 2)
		return (0);
	str = argv_to_string(argc - 1, argv + 1);
	if (processing_args(str, &input))
		return (write(2, "Error\n", 6), free_split(str), 1);
	stack_a = create_stack(str, &input, &count);
	if (!stack_a)
		return(write(2, "Error\n", 6), free_split(str), 1);
	strategy(&stack_a, &stack_b, &input, &count);
	if (is_sorted(&stack_a))
		ft_printf("ORGANIZADO!\n");
	else
		ft_printf("DESORGANIZADO!\n");
	
	return (free_split(str), free_stack(&stack_a), 0);
}
