/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 23:24:37 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/19 01:50:23 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	sig_int(void)
{
	if (g_pid == 0)
	{
		ft_putendl_fd("\b\b  ", 1);
		put_prompt();
		g_status = 1;
	}
	else
	{
		ft_putendl_fd("", 1);
		g_status = 130;
	}
}

static void	sig_quit(int sig)
{
	char	*code;

	if (g_pid == 0)
		ft_putstr_fd("\b\b  \b\b", 1);
	else
	{
		code = ft_itoa(sig);
		ft_putstr_fd("Quit: ", 1);
		ft_putendl_fd(code, 1);
		ft_free(code);
		g_status = 131;
	}
}

void		signal_handler(int sig)
{
	if (sig == SIGINT)
		sig_int();
	else
		sig_quit(sig);
}
