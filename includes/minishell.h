/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:13:49 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/18 15:16:20 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <unistd.h>

# include "../lib/libft/includes/libft.h"

int	execmd(char **args);
int	launch(char **args);

/*
** BUILTIN COMMANDS
*/

int	msh_exit(void);
int	msh_pwd(void);
int	msh_echo(char **args);
int	msh_cd(char **args);
int	msh_env(void);
int	msh_export(char **args);
int	msh_unset(char **args);




/*
 * temp
 */

int	msh_getenv(char **args);
int	msh_setenv(char **args);

#endif
