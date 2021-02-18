/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:28:37 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/19 03:05:43 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "easter.h"
# include "libft.h"
# include "minishell.h"
# include "utils.h"
# include <dirent.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/wait.h>

/*
** EXECUTE
*/

int		execmd(char **args);
int		launch(char **args);

/*
** BUILTIN COMMANDS
*/

int		msh_cd(char **args);
int		msh_echo(char **args);
int		msh_env(void);
int		msh_exit(char **args);
int		msh_export(char **args);
int		msh_pwd(void);
int		msh_unset(char **args);

#endif
