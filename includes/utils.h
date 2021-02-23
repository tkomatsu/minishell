/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:30:32 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/23 22:18:20 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*
** SELF-MADE HEADER FILES
*/
# include "error.h"
# include "libft.h"

/*
** EXTERNAL LIBRARIES
*/
# include <errno.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*
** MACRO DECLARATION - EXIT STATUS
*/
# define EX_EBUILTIN 2
# define EX_EPERM 126
# define EX_ENOENT 127
# define EX_EINVAL 128
# define EX_SIGNAL 128
# define EX_CTRLC 130
# define EX_OUTRANGE 255
# define EX_EINPUT 258

/*
** MACRO DECLARATION - LOOP STATUS
*/
# define EXIT_LOOP 0
# define STAY_LOOP 1

/*
** MACRO DECLARATION - RETURN VALUE
*/
# define INVALID_NAME -1

/*
** MACRO DECLARATION - FLAG
*/
# define OFF 0
# define ON 1

/*
** GLOBAL VARIABLES
*/
extern char		**g_env;
extern pid_t	g_pid;
extern int		g_status;
extern int		g_sigint;

/*
** PROTOTYPE DECLARATION
*/
void	exit_perror(char *err_msg, int exit_status);
char	*ft_getenv(const char *name);
void	ft_perror(char *s);
int		ft_putenv(const char *string);
int		ft_setenv(const char *name, const char *value, int overwrite);
int		ft_unsetenv(const char *name);
void	put_prompt(char *ps);
void	signal_handler(int sig);
void	signal_ignore(int sig);

#endif
