/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 16:42:28 by fbarrada          #+#    #+#             */
/*   Updated: 2026/06/15 18:55:40 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"
# include <stdlib.h>


typedef enum e_flags
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
	ERROR,
	
}	t_flags;

typedef struct s_input
{
	t_flags	strategy;
	int	*nums;
	int	count;
	int	start;
}	t_input;

typedef struct s_list
{
	int				value;
	struct s_list	*previous;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(int), void (*del)(int));
int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(int));
void				ft_lstclear(t_list **lst, void (*del)(int));
void				ft_lstiter(t_list *lst, void (*f)(int));

#endif
