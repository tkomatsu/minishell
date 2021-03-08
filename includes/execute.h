/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:28:37 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/08 13:12:16 by kefujiwa         ###   ########.fr       */
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
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/wait.h>

/*
** MACRO DECLARATION - EXECUTE
*/
# define EXECUTABLE 1

/*
** PROTOTYPE DECLARATION - EXECUTE
*/
int		execmd(char **args);
int		launch(char **args);

/*
** PROTOTYPE DECLARATION - BUILTIN COMMANDS
*/
int		ft_cd(char **args);
int		ft_echo(char **args);
int		ft_env(void);
int		ft_exit(char **args);
int		ft_export(char **args);
int		ft_pwd(void);
int		ft_unset(char **args);
int		help(char **args);

#endif
