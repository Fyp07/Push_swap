# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/28 13:50:18 by fbarrada          #+#    #+#              #
#    Updated: 2026/05/12 15:58:27 by fbarrada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CCFLAGS = -Wall -Wextra -Werror

SRC =   ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_toupper.c ft_tolower.c ft_memset.c ft_bzero.c ft_memcpy.c \
	ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c \
	ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c \
	ft_strdup.c ft_atoi.c ft_calloc.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	ft_lstmap.c

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
