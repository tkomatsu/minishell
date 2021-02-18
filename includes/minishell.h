/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:13:49 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/19 02:20:11 by kefujiwa         ###   ########.fr       */
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

extern char		**g_env;
extern pid_t	g_pid;
extern int		g_status;

#endif
