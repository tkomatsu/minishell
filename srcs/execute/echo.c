/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 22:26:33 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/18 21:11:15 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	msh_echo(char **args)
{
	int		i;
	_Bool	noption;

	i = 1;
	noption = false;
	if (!args[1])
	{
		ft_putchar_fd('\n', 1);
		return (1);
	}
	if (!ft_strcmp(args[i], "-n"))
	{
		noption = true;
		i++;
	}
	while (args[i])
	{
		if (i >= 3 || (i == 2 && !noption))
			ft_putchar_fd(' ', 1);
		ft_putstr_fd(args[i], 1);
		i++;
	}
	if (!noption)
		ft_putchar_fd('\n', 1);
	return (1);
}
