# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: garodri2 <garodri2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/17 16:35:13 by fbarrada          #+#    #+#              #
#    Updated: 2026/07/03 15:28:16 by garodri2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MKDIR_P	= mkdir -p

NAME = push_swap

CC = cc

FLAGS = -Wall -Wextra -Werror -g

INCLUDES = -ILibft

LIBFT_PATH = Libft/libft.a

PRINTF_SRCS = ft_printf/ft_printf.c ft_printf/ft_printptr.c ft_printf/printf_helpers.c \

LISTAS_SRCS = listas/ft_lstnew.c listas/ft_lstadd_front.c listas/ft_lstsize.c listas/ft_lstlast.c \
				listas/ft_lstadd_back.c

SRCS = ft_stack.c operations.c main.c parsing.c validations.c sort_five.c innit_count.c $(PRINTF_SRCS) $(LIBFT_SRCS) $(LISTAS_SRCS)

#OBJ = $(SRCS:.c=.o)

SRC_PATH		= .
BUILD_PATH		= .build

BONUS_FILES	= main_bonus.c free_bonus.c utils_bonus.c pipes_bonus.c

SRC						= $(addprefix $(SRC_PATH)/, $(SRCS))
OBJS					= $(SRC:$(SRC_PATH)/%.c=$(BUILD_PATH)/%.o)

all: $(LIBFT_PATH) $(NAME)

$(LIBFT_PATH):
	$(MAKE) -C Libft/

$(NAME): $(BUILD_PATH) $(OBJS) $(LIBFT_PATH)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT_PATH) -o $(NAME)
	
#%.o: %.c
#	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c $(INCLUDES)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(BUILD_PATH):
	@$(MKDIR_P) $(BUILD_PATH)
	@echo "Creating $(BUILD_PATH) folder ✔︎ 📂"

clean:
	$(MAKE) -C Libft/ clean
	rm -rf .build
#	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C Libft/ fclean
	rm -f $(NAME)
	
re: fclean all
	
.PHONY: all clean fclean re
