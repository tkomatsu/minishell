/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 23:23:13 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/16 01:09:09 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exit_error(char **args, int len, int num)
{
	errno = num;
	if (num == 204)
	{
		g_status = 255;
		ft_putstr_fd("minish: exit: ", 2);
		ft_perror(args[len]);
		return (0);
	}
	else
	{
		g_status = EXIT_FAILURE;
		ft_putstr_fd("minish: ", 2);
		ft_perror(args[0]);
		return (1);
	}
}

static int	within_range(char *str, int is_negative)
{
	unsigned long long	num;
	unsigned long long	max;
	int					digit;

	num = 0;
	max = 9223372036854775807;
	digit = 7;
	if (is_negative)
		digit = 8;
	while (*str)
	{
		if (num < max / 10 || (num == max / 10 && *str - '0' <= digit))
			num = num * 10 + (*str - '0');
		else
			return (0);
		str++;
	}
	return (1);
}

static int	is_numeric(char *str)
{
	int		is_negative;
	char	*num;

	is_negative = 0;
	str = ft_strtrim(str, " ");
	if (*str == '-' || *str == '+')
	{
		is_negative = (*str == '-' ? 1 : 0);
		str++;
	}
	num = str;
	while (*str)
		if (!ft_isdigit(*(str++)))
			return (0);
	return (within_range(num, is_negative));
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
