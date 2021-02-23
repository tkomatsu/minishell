/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 23:24:37 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/23 02:11:53 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	sig_int(void)
{
	if (g_pid == 0)
	{
		ft_putendl_fd("\b\b  ", STDOUT);
		put_prompt("PS1");
		g_status = EXIT_FAILURE;
		g_sigint = ON;
	}
	else
	{
		ft_putendl_fd("", STDOUT);
		g_status = EX_CTRLC;
	}
}

static void	sig_quit(int sig)
{
	char	*code;

	if (g_pid == 0)
		ft_putstr_fd("\b\b  \b\b", STDOUT);
	else
	{
		code = ft_itoa(sig);
		ft_putstr_fd("Quit: ", STDOUT);
		ft_putendl_fd(code, STDOUT);
		ft_free(code);
		g_status = EX_SIGNAL + sig;
	}
}

void		signal_handler(int sig)
{
	if (sig == SIGINT)
		sig_int();
	else
		sig_quit(sig);
}
