# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbarrada <fbarrada@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/28 13:50:18 by fbarrada          #+#    #+#              #
#    Updated: 2026/07/03 13:47:33 by fbarrada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CCFLAGS = -Wall -Wextra -Werror

SRC =   ft_atoi.c ft_putstr_fd.c ft_split.c ft_strjoin.c ft_strlen.c ft_calloc.c ft_bzero.c \

HEADER = libft.h

NAME = libft.a

COMP = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(COMP)
	ar rcs $(NAME) $(COMP)

%.o: %.c $(HEADER)
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(COMP)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
