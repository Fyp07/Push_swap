/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 16:42:28 by fbarrada          #+#    #+#             */
/*   Updated: 2026/07/10 14:59:51 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef enum e_flags
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
	ERROR,
}					t_flags;

typedef struct s_input
{
	t_flags			strategy;
	int				count;
	int				start;
	int				bench;
	float			disorder;
}					t_input;

typedef struct s_count
{
	int				sa;
	int				sb;
	int				ss;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				pa;
	int				pb;
	int				size_a;
	int				size_b;
	int				total;
}					t_count;

typedef struct s_list
{
	int				value;
	int				rank;
	struct s_list	*previous;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(int content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int));
t_list				*create_stack(char **str, int start, t_input *input,
						t_count *count);
t_list				*find_min(t_list **list);
t_list				*find_max(t_list **list);
t_list				*set_bucket_ranks(t_list **stack, int total_size, t_flags flag);

int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(int));
void				ft_lstclear(t_list **lst, void (*del)(int));
void				ft_lstiter(t_list *lst, void (*f)(int));
int					ft_lstmin(t_list *lst);
int					ft_lstmax(t_list *lst);

int					index_max(t_list *stack);
int					nearest_position(t_list *stack_b, int value);
int					find_nearest(t_list **stack_b, int element_stack_a);
int					cost_to_insert(t_list *stack_b, int element_stack_a,
						int position_element_a, int size_stack_a);
int					search_cheapest(t_list *stack_a, t_list *stack_b);
void				rotation_b(t_list **stack_b, t_count *count, int position);
void				rotation_a(t_list **stack_a, t_count *count, int position);
void				go_min(t_list **stack_b, t_count *count);
void				go_back_home(t_list **stack_a, t_list **stack_b,
						t_count *count);
void				sum_operations(t_count *count);

void				print_stack(t_list *stack, char *name);
void				print_ranks(t_list *stack);
void				print_benchmark(t_input *input, t_count *count);
void				print_stack_a_b(t_list *stack_a, t_list *stack_b);

void				sa(t_list **lista, t_count *count);
void				sb(t_list **list_b, t_count *count);
void				ss(t_list **list_a, t_list **list_b, t_count *count);
void				pa(t_list **list_a, t_list **list_b, t_count *count);
void				pb(t_list **list_b, t_list **list_a, t_count *count);
void				ra(t_list **list_a, t_count *count);
void				rb(t_list **list_b, t_count *count);
void				rr(t_list **list_b, t_list **list_a, t_count *count);
void				rra(t_list **list_a, t_count *count);
void				rrb(t_list **list_b, t_count *count);
void				rrr(t_list **list_a, t_list **list_b, t_count *count);

void				sort_two(t_list **list, t_count *count);
void				sort_three(t_list **a, t_count *count);
void				sort_five(t_list **a, t_list **b, t_count *count,
						t_input *input);
void				simple_insertion(t_list **stack_a, t_list **stack_b,
						t_count *count);
void				chunk_insertion(t_list **stack_a, t_list **stack_b,
						int rank, t_count *count);
void				chunk_sort(t_list **stack_a, t_list **stack_b,
						t_count *count, t_input *input);

void				validate_flags(char **str, t_input *input);
void				free_stack(t_list **list);

float				compute_disorder(t_list **stack_a);
void				disorder_check(t_list **stack_a, t_list **stack_b,
						t_input *input, t_count *count);
void				strategy(t_list **stack_a, t_list **stack_b, t_input *input,
						t_count *count);

int					processing_args(char **str, t_input *input);
int					check_errors(char **numbers);
int					is_not_num(char *str);
int					has_repeated(char **numbers);
int					in_range(char *numbers);
int					is_sorted(t_list **array);
int					is_stack_b_sorted(t_list **list);
int					ft_strcmp(char *s1, char *s2);
int					min_position(t_list **list);
int					max_position(t_list **list);
int					ft_sqrt(int num);
int					has_rank(t_list *list, int rank);
int					number_of_ranks(t_list *list);
int					find_rank_pos(t_list *list, int rank);

long				ft_atol(const char *nptr);

char				*join(char *str, char **argv);
char				**argv_to_string(int argc, char **argv);

#endif
