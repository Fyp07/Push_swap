#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
    int            content;
    struct s_list    *next;
}                    t_list;

t_list    *ft_lstlast(t_list *lst)
{
    t_list    *last;
    t_list    *current;

    if (!lst)
        return (NULL);
    current = lst;
    while (current != NULL)
    {
        last = current;
        current = current->next;
    }
    return (last);
}

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list    *current;

    if (!lst || !new)
        return ;
    if (!*lst)
        *lst = new;
    else
    {
        current = ft_lstlast(*lst);
        current->next = new;
    }
}


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
// Meu hobby? Amar 
