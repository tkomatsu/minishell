/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:13:49 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/22 10:55:47 by tkomatsu         ###   ########.fr       */
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

int		execmd(char **args);
int		launch(char **args);

int		read_arg(char **line);

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

char	*ft_getenv(const char *name);
int		ft_putenv(const char *string);
int		ft_setenv(const char *name, const char *value, int overwrite);
int		ft_unsetenv(const char *name);

#endif
