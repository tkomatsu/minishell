/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 22:26:33 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/23 04:41:59 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	ft_echo(char **args)
{
	int		i;
	_Bool	noption;

	i = 1;
	noption = false;
	if (!args[1])
	{
		ft_putchar_fd('\n', STDOUT);
		return (STAY_LOOP);
	}
	if (!ft_strcmp(args[i], "-n"))
	{
		noption = true;
		i++;
	}
	while (args[i])
	{
		if (i >= 3 || (i == 2 && !noption))
			ft_putchar_fd(' ', STDOUT);
		ft_putstr_fd(args[i++], STDOUT);
	}
	if (!noption)
		ft_putchar_fd('\n', STDOUT);
	g_status = EXIT_SUCCESS;
	return (STAY_LOOP);
}
