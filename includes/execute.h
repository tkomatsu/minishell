/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:28:37 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/19 12:45:39 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

/*
** SELF-MADE HEADER FILES
*/

# include "easter.h"
# include "error.h"
# include "libft.h"
# include "utils.h"

/*
** EXTERNAL LIBRARIES
*/

# include <dirent.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/wait.h>

/*
** PROTOTYPE DECLARATION - EXECUTE
*/

int		execmd(char **args);
int		launch(char **args);

/*
** PROTOTYPE DECLARATION - BUILTIN COMMANDS
*/

int		msh_cd(char **args);
int		msh_echo(char **args);
int		msh_env(void);
int		msh_exit(char **args);
int		msh_export(char **args);
int		msh_pwd(void);
int		msh_unset(char **args);

#endif
