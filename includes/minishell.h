/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:13:49 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/18 15:21:09 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>

# define QUOTE 0x01
# define DQUOTE 0x02
# define ESC 0x04

extern char		**g_env;
extern pid_t	g_pid;
extern int		g_status;

/*
** READ
*/

typedef struct	s_token
{
	char			*word;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}				t_token;

# define WORD 1
# define NEWLINE 2
# define PIPE 3
# define AND 4
# define SEMICOLON 5
# define P_OPEN 6
# define P_CLOSE 7
# define GREATER 8
# define LESS 9

int		read_stdin(char **line);
t_token	*split_tokens(char *line);

/*
** PARSE
*/

int		run_cmd(void *content, int flag);
int		ft_lstiter_sta(t_list *lst, int (*f)(void *, int));
int		parse_exec(t_token *tokens);
void	parse_tokens(void *content);
char	*parse_var(char *str, char *new, char **head, char **ptr);
char	**convert_lst_to_args(t_token *tokens);
void	convert_esc(char **args);
char	*convert_quotes(char *str, char **ptr);
char	*convert_dquotes(char *str, char **ptr);
char	*convert_words(char *str, char **ptr);

/*
** EXECUTE
*/

int		execmd(char **args, int flag);
int		launch(char **args);

/*
** BUILTIN COMMANDS
*/

int		msh_exit(char **args);
int		msh_pwd(void);
int		msh_echo(char **args);
int		msh_cd(char **args);
int		msh_env(void);
int		msh_export(char **args);
int		msh_unset(char **args);

/*
** UTILITY
*/

void	clear_tokens(t_token **tokens);
void	exit_perror(char *err_msg, int exit_status);
int		token_size(t_token *tokens);
char	*ft_getenv(const char *name);
void	ft_perror(char *s);
int		ft_putenv(const char *string);
int		ft_setenv(const char *name, const char *value, int overwrite);
int		ft_unsetenv(const char *name);
void	put_prompt(void);
t_token	*dlistnew(char *src, int sep);
t_token *dlisthead(t_token *tokens);
t_token	*dlistlast(t_token *tokens);
void	dlist_add_back(t_token **list, t_token *new);
void	signal_handler(int sig);
void	signal_ignore(int sig);
int		get_next_input(int fd, char **line);

/*
** EASTER EGG
*/
int		is_ultimate_question(char **args);

#endif
