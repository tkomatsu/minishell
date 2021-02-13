/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 23:23:13 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/14 03:07:38 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exit_error(char **args, int len, int num)
{
	g_status = EXIT_FAILURE;
	errno = num;
	if (num == 204)
	{
		ft_putstr_fd("minish: exit: ", 2);
		ft_perror(args[len]);
		return (0);
	}
	else
	{
		ft_putstr_fd("minish: ", 2);
		ft_perror(args[0]);
		return (1);
	}
}

static int	is_numeric(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int			msh_exit(char **args)
{
	int	len;

	len = 0;
	ft_putendl_fd("exit", 1);
	while (args[len])
	{
		if (len == 1 && !is_numeric(args[len]))
			return (exit_error(args, len, 204));
		else if (len >= 2)
			return (exit_error(args, len, 205));
		len++;
	}
	if (len == 2)
		g_status = ft_atoi(args[1]);
	return (0);
}
