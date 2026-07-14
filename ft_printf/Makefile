# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/18 10:45:34 by fbarrada          #+#    #+#              #
#    Updated: 2026/05/18 11:55:24 by fbarrada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CCFLAGS = -Wall -Wextra -Werror

SRC =   ft_printf.c ft_printptr.c helpers.c \

HEADER = ft_printf.h

NAME = libftprintf.a

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