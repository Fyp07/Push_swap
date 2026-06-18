
#include "push_swap.h"

// typedef struct s_list
// {
//     int            content;
//     struct s_list    *next;
// }                    t_list;

// t_list    *ft_lstlast(t_list *lst)
// {
//     t_list    *last;
//     t_list    *current;

//     if (!lst)
//         return (NULL);
//     current = lst;
//     while (current != NULL)
//     {
//         last = current;
//         current = current->next;
//     }
//     return (last);
// }

// void    ft_lstadd_back(t_list **lst, t_list *new)
// {
//     t_list    *current;

//     if (!lst || !new)
//         return ;
//     if (!*lst)
//         *lst = new;
//     else
//     {
//         current = ft_lstlast(*lst);
//         current->next = new;
//     }
// }


// t_list    *ft_lstnew(int content) // Cria um novo no
// {
//     t_list    *lst;

//     lst = malloc(sizeof(t_list));
//     if (!lst)
//         return (NULL);
//     lst->content = content;
//     lst->next = NULL;
//     return (lst);
// }

// t_list	*create_list(int size, int *numbers[])
// {
//   t_list *head = NULL;
//   t_list *tail;
//   t_list *node;
  
//   int i = 0;
//   while (i < size)
//   {
//     node = ft_lstnew(numbers[i]);
//     if (!head)
//       head = node;
//     else
//       ft_lstadd_back(&head, node);
//     tail = node;
//     i++;
//   }
//   return (head);
// }

// ./a.out --simple 12 345 "12 43 12" 12 -> ./a.out "--simple 2 345 1 42 12" -> ft_split = "--simple", "2", "345", "1", "42", "12" -> Verificacao = return (0); -> 12 345 12 42 12 12

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
	t_input *input;
	char **str;
	int	i;
	
	i = 0;
	input = malloc(sizeof(t_input));
	if (argc < 2)
		return (0);
	str = argv_to_string(argc - 1, argv + 1);
	validate_numbers(argc, argv, input);
	while (str[i])
		printf("%s ", str[i++]);
	free_split(str);
	free(input);
	return (0);
}

// char string[] == "hello" 
// *(string + 5)
// char *str = "Felyppe";
// *str + 1;
// [./a.out][1][2][6] // [NULL]

// int	main()
// {
// 	t_list	*stack_a;
// 	t_list	*temp;

// 	int numbers[] = {10, 3, 7, 152, 34, -1, 20, 10, 40, 10, 3, 14, -5};

// 	stack_a = create_list(numbers, sizeof(numbers) / sizeof(int));
// 	temp = stack_a;
// 	while (temp->next)
// 	{
// 		printf("%d -> ", temp->content);
// 		temp = temp->next;
// 	}
// 	printf("NULL\n");
// 	return (0);
// }

// teste 2
// Meu hobby? Amar 
