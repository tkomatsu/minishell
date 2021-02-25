/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 22:26:33 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/25 15:55:23 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static _Bool	check_noption(char *s)
{
	if (*s != '-')
		return (false);
	s++;
	while (*s)
	{
		if (*s != 'n')
			return (false);
		s++;
	}
	return (true);
}

static int		return_void(void)
{
	ft_putchar_fd('\n', STDOUT);
	return (STAY_LOOP);
}

int				ft_echo(char **args)
{
	int		i;
	_Bool	noption;
	_Bool	padding;

	i = 1;
	noption = false;
	if (!args[1])
		return (return_void());
	while (check_noption(args[i]))
	{
		noption = true;
		i++;
	}
	padding = false;
	while (args[i])
	{
		if (padding)
			ft_putchar_fd(' ', STDOUT);
		ft_putstr_fd(args[i++], STDOUT);
		padding = true;
	}
	if (noption == false)
		ft_putchar_fd('\n', STDOUT);
	g_status = EXIT_SUCCESS;
	return (STAY_LOOP);
}
