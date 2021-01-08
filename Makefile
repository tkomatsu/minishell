# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/08 20:22:12 by tkomatsu          #+#    #+#              #
#    Updated: 2021/01/08 21:11:23 by tkomatsu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
_GREY	= \x1b[30m
_RED	= \x1b[31m
_GREEN	= \x1b[32m
_YELLOW	= \x1b[33m
_BLUE	= \x1b[34m
_PURPLE	= \x1b[35m
_CYAN	= \x1b[36m
_WHITE	= \x1b[37m
_END	= \x1b[0m

NAME = minishell

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I $(INCLUDE)
FLAGS = -L $(LIB)libft -lft

DEBUG_CFLAGS = -g3

INCLUDE = includes
SRC_DIR = srcs/
LIB = lib/

SRC_FILES =	main.c

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB)libft
	@$(CC) $(CFLAGS) $(OBJS) $(FLAGS) -o $@
	@echo "$(_GREEN)Finish compiling $(NAME)!"
	@echo "Try \"./$(NAME)\" to use$(_END)"

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@ 

debug: CFLAGS += -fsanitize=address $(DEBUG_CFLAGS)
debug: re
	@echo "$(_BLUE)Debug build done$(_END)"

clean:
	@echo "$(_YELLOW)Removing object files ...$(_END)"
	@make clean -C $(LIB)libft
	@make clean -C $(LIB)libvct
	@rm -f $(OBJS)
	@rm -fr *.dSYM

fclean:
	@echo "$(_RED)Removing object files and program ...$(_END)"
	@make fclean -C $(LIB)libft
	@make fclean -C $(LIB)libvct
	@rm -f $(NAME) $(OBJS)
	@rm -fr *.dSYM

re: fclean all

PHONY: all clean fclean re

