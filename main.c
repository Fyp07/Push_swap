/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 17:06:54 by fbarrada          #+#    #+#             */
/*   Updated: 2026/06/25 15:32:30 by fbarrada         ###   ########.fr       */
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
	t_list *stack_b;
	char **str;
	
	stack_b = NULL;
	if (argc < 2)
		return (0);
	str = argv_to_string(argc - 1, argv + 1); // Faz o seguinte: 1 2 "3 4 5" 6 7; -> 1 2 3 4 5 6 7;
	if (processing_args(str, &input)) // Verifica se os argumentos sao validos
		return (write(2, "Error\n", 6), free_split(str), 1); // Se houver um erro, retorna uma mensagem de erro, da free em tudo e retorna 1);
	stack_a = create_stack(str, input.start); // Cria a stack;
	if (!stack_a)
		return(write(2, "Error\n", 6), free_split(str), 1);
	print_stack(stack_a, "A");
	rra(&stack_a);
	print_stack(stack_a, "A");
	

	return (free_split(str), 0);
}
<<<<<<< HEAD


t_list    *ft_lstnew(int content) // Cria um novo no
{
    t_list    *lst;

    lst = malloc(sizeof(t_list));
    if (!lst)
        return (NULL);
    lst->content = content;
    lst->next = NULL;
    return (lst);
}

t_list	*programa(void)
{
  t_list *head = NULL;
  t_list *tail;
  t_list *node;
  
  int i = 0;
  int numeros[] = {10, 3, 7, 152, 34, -1, 20, 10, 40, 10, 3, 14, -5};
  int size = sizeof(numeros) / 4;
  
  while (i < size)
  {
    node = ft_lstnew(numeros[i]);
    if (!head)
      head = node;
    else
      ft_lstadd_back(&head, node);
    tail = node;
    i++;
  }
  return (head);
}

int	main()
{
	t_list	*stack_a;
	t_list	*temp;

	stack_a = programa();
	temp = stack_a;
	while (temp->next)
	{
		printf("%d -> ", temp->content);
		temp = temp->next;
	}
	printf("NULL\n");
	return (0);
}

// teste
// Meu hobby? Amar demais
// Bora bill 67 labubu Carlinhos maia farmador de aura Vivi+Vini Casalzao
=======
>>>>>>> a447ce169aa68a8279fdcdef1bd008d67127bab4
