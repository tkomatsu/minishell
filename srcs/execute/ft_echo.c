/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 22:26:33 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/19 14:22:56 by tkomatsu         ###   ########.fr       */
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
		ft_putstr_fd(args[i], STDOUT);
		i++;
	}
	if (!noption)
		ft_putchar_fd('\n', STDOUT);
	return (STAY_LOOP);
}
