# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/08 20:22:12 by tkomatsu          #+#    #+#              #
#    Updated: 2021/01/19 22:13:23 by tkomatsu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
# ****************************************************************************

_GREY	= \033[30m
_RED	= \033[31m
_GREEN	= \033[32m
_YELLOW	= \033[33m
_BLUE	= \033[34m
_PURPLE	= \033[35m
_CYAN	= \033[36m
_WHITE	= \033[37m
_END	= \033[0m

# ****************************************************************************

NAME = minishell

# Config
# ****************************************************************************

CC = gcc

INCLUDE = includes

CFLAGS = -Wall -Werror -Wextra -I $(INCLUDE)
FLAGS = -L $(LIB)libft -lft

DEBUG_CFLAGS = -g3

# Source files
# ****************************************************************************

# read

READ_DIR = read/
READ_FILES = read_arg.c

READ_SRCS = $(addprefix $(READ_DIR), $(READ_FILES))

# parse

PARSE_DIR = parse/
PARSE_FILES = 

PARSE_SRCS = $(addprefix $(PARSE_DIR), $(PARSE_FILES))

# execute

EXE_DIR = execute/
EXE_FILES = execmd.c \
			builtin.c \
			builtin_env.c \
			launch.c

EXE_SRCS = $(addprefix $(EXE_DIR), $(EXE_FILES))

# utility

UTIL_DIR = utils/
UTIL_FILES = ft_getenv.c \
			 ft_putenv.c \
			 ft_setenv.c

UTIL_SRCS = $(addprefix $(UTIL_DIR), $(UTIL_FILES))

# addprefix

SRC_DIR = srcs/
LIB = lib/

SRC_FILES =	minishell.c \
			$(READ_SRCS) \
			$(PARSE_SRCS) \
			$(EXE_SRCS) \
			$(UTIL_SRCS)

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJS = $(SRCS:.c=.o)

# Recipe
# ****************************************************************************

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(_END)\nCompiled source files"
	@make -C $(LIB)libft
	@$(CC) $(CFLAGS) $(OBJS) $(FLAGS) -o $@
	@echo "$(_GREEN)Finish compiling $(NAME)!"
	@echo "Try \"./$(NAME)\" to use$(_END)"

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@ 
	@printf "$(_GREEN)█"

debug: CFLAGS += -fsanitize=address $(DEBUG_CFLAGS)
debug: re
	@echo "$(_BLUE)Debug build done$(_END)"

clean:
	@echo "$(_YELLOW)Removing object files ...$(_END)"
	@make clean -C $(LIB)libft
	@rm -f $(OBJS)
	@rm -fr *.dSYM

fclean:
	@echo "$(_RED)Removing object files and program ...$(_END)"
	@make fclean -C $(LIB)libft
	@rm -f $(NAME) $(OBJS)
	@rm -fr *.dSYM

re: fclean all

PHONY: all clean fclean re

