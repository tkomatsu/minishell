/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:13:49 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/04 17:46:33 by tkomatsu         ###   ########.fr       */
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

# define QUOTE 1
# define DQUOTE 2

extern char	**g_env;

/*
** READ
*/

typedef struct	s_token
{
	char			*word;
	int				type;
	struct s_token	*next;
	struct s_token	*prev;
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

int		parse_exec(char *line);
void	convert_esc(char **args);

/*
** EXECUTE
*/

int		execmd(char **args);
int		launch(char **args);

/*
** BUILTIN COMMANDS
*/

int		msh_exit(void);
int		msh_pwd(void);
int		msh_echo(char **args);
int		msh_cd(char **args);
int		msh_env(void);
int		msh_export(char **args);
int		msh_unset(char **args);

/*
** UTILITY
*/

void	del_token(void *ptr);
char	*ft_getenv(const char *name);
void	ft_perror(char *s);
int		ft_putenv(const char *string);
int		ft_setenv(const char *name, const char *value, int overwrite);
int		ft_unsetenv(const char *name);

/*
** EASTER EGG
*/
int		is_ultimate_question(char **args);

#endif
