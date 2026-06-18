
#include "push_swap.h"

t_list	*create_list(int size, int *numbers[])
{
  t_list *head = NULL;
  t_list *tail;
  t_list *node;
  
  int i = 0;
  while (i < size)
  {
    node = ft_lstnew(numbers[i]);
    if (!head)
      head = node;
    else
      ft_lstadd_back(&head, node);
    tail = node;
    i++;
  }
  return (head);
}

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
	
	free_split(str);
	free(input);
	return (0);
}
