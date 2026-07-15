# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: garodri2 <garodri2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/17 16:35:13 by fbarrada          #+#    #+#              #
#    Updated: 2026/07/15 12:07:31 by garodri2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC = cc

FLAGS = -Wall -Wextra -Werror -g

INCLUDES = -ILibft

LIBFT_PATH = Libft/libft.a

OBJ_DIR = obj

LISTAS_SRCS = listas/ft_lstnew.c \
			  listas/ft_lstadd_front.c \
			  listas/ft_lst_helpers.c \
			  listas/ft_lstlast.c \
			  listas/ft_lstadd_back.c

SRCS = ft_stack.c \
	   push_swap_operations.c \
	   rotation_operations.c \
	   main.c \
	   parsing.c \
	   validations.c \
	   sort_utils.c \
	   medium.c \
	   simple.c \
	   simple_utils.c \
	   complex.c \
	   ranks.c \
	   ft_printf.c \
	   bench.c \
	   strategy.c \
	   position_utils.c \
	   algorithms_utils.c \
	   disorder.c \
	   $(LISTAS_SRCS)

OBJ = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

all: $(LIBFT_PATH) $(NAME)

$(LIBFT_PATH):
	$(MAKE) -C Libft

$(NAME): $(OBJ) $(LIBFT_PATH)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT_PATH) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C Libft clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C Libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
