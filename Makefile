# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbarrada <fbarrada@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/17 16:35:13 by fbarrada          #+#    #+#              #
#    Updated: 2026/07/13 15:16:14 by fbarrada         ###   ########.fr        #
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
	   operations.c \
	   main.c \
	   parsing.c \
	   validations.c \
	   sort_five.c \
	   medium.c \
	   simple.c \
	   complex.c \
	   ranks.c \
	   ft_printf.c \
	   bench.c \
	   choose_strategy.c \
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
