/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:13:49 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/26 21:59:55 by tkomatsu         ###   ########.fr       */
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
	char *word;
	int metachar;
}				t_token;

# define SPACE		(1<<1)	// ' '
# define TAB		(1<<2)	// '\t'
# define NEWLINE	(1<<3)	// '\n'
# define PIPE		(1<<4)	// '|'
# define AMPERSAND	(1<<5)	// '&'
# define SEMICOLON	(1<<6)	// ';'
# define P_BEGIN	(1<<7)	// '('
# define P_END		(1<<8)	// ')'
# define GREATER	(1<<9)	// '>'
# define LESS		(1<<10)	// '<'

t_list	*read_tokens(void);
int		read_arg(char **line);

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
