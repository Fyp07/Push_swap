# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbarrada <fbarrada@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/17 16:35:13 by fbarrada          #+#    #+#              #
#    Updated: 2026/06/29 14:32:24 by fbarrada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

FLAGS = -Wall -Wextra -Werror -g

PRINTF_SRCS = ft_printf/ft_printf.c ft_printf/ft_printptr.c ft_printf/printf_helpers.c

LIBFT_SRCS = Libft/ft_isalpha.c Libft/ft_isdigit.c Libft/ft_isalnum.c Libft/ft_isascii.c Libft/ft_isprint.c \
            Libft/ft_toupper.c Libft/ft_tolower.c Libft/ft_memset.c Libft/ft_bzero.c Libft/ft_memcpy.c \
            Libft/ft_memmove.c Libft/ft_memchr.c Libft/ft_memcmp.c Libft/ft_strlen.c Libft/ft_strlcpy.c \
            Libft/ft_strlcat.c Libft/ft_strchr.c Libft/ft_strrchr.c Libft/ft_strncmp.c Libft/ft_strnstr.c \
            Libft/ft_strdup.c Libft/ft_atoi.c Libft/ft_calloc.c Libft/ft_substr.c Libft/ft_strjoin.c \
            Libft/ft_strtrim.c Libft/ft_split.c Libft/ft_itoa.c Libft/ft_strmapi.c Libft/ft_striteri.c \
            Libft/ft_putchar_fd.c Libft/ft_putstr_fd.c Libft/ft_putendl_fd.c Libft/ft_putnbr_fd.c

LISTAS_SRCS = listas/ft_lstnew.c listas/ft_lstadd_front.c listas/ft_lstsize.c listas/ft_lstlast.c \
             listas/ft_lstadd_back.c listas/ft_lstdelone.c listas/ft_lstclear.c listas/ft_lstiter.c listas/ft_lstmap.c

SRCS = ft_stack.c operations.c main.c parsing.c validations.c simple_sort.c $(PRINTF_SRCS) $(LIBFT_SRCS) $(LISTAS_SRCS)

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	
re: fclean all
	
.PHONY: all clean fclean re
