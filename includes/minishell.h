/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:13:49 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/19 03:23:30 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "parse.h"
# include "read.h"
# include "token.h"
# include "utils.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

/*
** FILE DESCRIPTOR
*/

# define STDIN 0
# define STDOUT 1
# define STDERR 2

/*
** LOOP STATUS
*/

# define EXIT_LOOP 0
# define STAY_LOOP 1

extern char		**g_env;
extern pid_t	g_pid;
extern int		g_status;

#endif
