# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/08 20:22:12 by tkomatsu          #+#    #+#              #
#    Updated: 2021/02/24 23:09:44 by kefujiwa         ###   ########.fr        #
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
READ_FILES = read_stdin.c \
			 tokenize.c \
			 get_next_input.c \
			 syntax_check.c

READ_SRCS = $(addprefix $(READ_DIR), $(READ_FILES))

# parse

PARSE_DIR = parse/
PARSE_FILES = convert_dquotes.c \
			  convert_quotes.c \
			  convert_words.c \
			  expand_tokens.c \
			  expand_environ.c \
			  parse_exec.c \
			  run_cmd.c \
			  run_pipeline.c \
			  set_redirect.c \
			  token_to_args.c

PARSE_SRCS = $(addprefix $(PARSE_DIR), $(PARSE_FILES))

# execute

EXE_DIR = execute/
EXE_FILES = execmd.c \
			ft_cd.c \
			ft_echo.c \
			ft_env.c \
			ft_exit.c \
			ft_export.c \
			ft_pwd.c \
			ft_unset.c \
			launch.c

EXE_SRCS = $(addprefix $(EXE_DIR), $(EXE_FILES))

# utility

UTIL_DIR = utils/
UTIL_FILES = clear_tokens.c \
			 exit_perror.c \
			 ft_getenv.c \
			 ft_perror.c \
			 ft_putenv.c \
			 ft_setenv.c \
			 ft_unsetenv.c \
			 put_prompt.c \
			 signal_handler.c \
			 signal_ignore.c \
			 token_utils.c \
			 token_size.c

UTIL_SRCS = $(addprefix $(UTIL_DIR), $(UTIL_FILES))

# easter egg

EASTER_DIR = easter/
EASTER_FILES = is_ultimate_question.c

EASTER_SRCS = $(addprefix $(EASTER_DIR), $(EASTER_FILES))

# addprefix

SRC_DIR = srcs/
LIB = lib/

SRC_FILES =	minishell.c \
			$(READ_SRCS) \
			$(PARSE_SRCS) \
			$(EXE_SRCS) \
			$(UTIL_SRCS) \
			$(EASTER_SRCS)


OBJ_DIR = objs/
OBJS = $(SRC_FILES:%.c=$(OBJ_DIR)%.o)

# Recipe
# ****************************************************************************

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(_END)\nCompiled source files"
	@make -C $(LIB)libft
	@$(CC) $(CFLAGS) $(OBJS) $(FLAGS) -o $@
	@echo "$(_GREEN)Finish compiling $(NAME)!"
	@echo "Try \"./$(NAME)\" to use$(_END)"

$(OBJS): $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ 
	@printf "$(_GREEN)█"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)$(READ_DIR)
	@mkdir -p $(OBJ_DIR)$(PARSE_DIR)
	@mkdir -p $(OBJ_DIR)$(EXE_DIR)
	@mkdir -p $(OBJ_DIR)$(UTIL_DIR)
	@mkdir -p $(OBJ_DIR)$(EASTER_DIR)

debug: CFLAGS += -fsanitize=address $(DEBUG_CFLAGS)
debug: re
	@echo "$(_BLUE)Debug build done$(_END)"

clean:
	@echo "$(_YELLOW)Removing object files ...$(_END)"
	@make clean -C $(LIB)libft
	@rm -rf $(OBJ_DIR)
	@rm -fr *.dSYM

fclean:
	@echo "$(_RED)Removing object files and program ...$(_END)"
	@make fclean -C $(LIB)libft
	@rm -rf $(NAME) $(OBJ_DIR)
	@rm -fr *.dSYM

test: all
	@cd test && bash grademe.sh

re: fclean all

PHONY: all clean fclean re

