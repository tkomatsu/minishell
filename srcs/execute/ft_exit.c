/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 23:23:13 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/03/08 15:37:09 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static int	exit_error(char **args, int len, int num)
{
	errno = num;
	if (num == E_NUMERIC)
	{
		g_status = EX_EBUILTIN;
		ft_putstr_fd("minish: exit: ", STDERR);
		ft_perror(args[len]);
		return (EXIT_LOOP);
	}
	else
	{
		g_status = EXIT_FAILURE;
		ft_putstr_fd("minish: ", STDERR);
		ft_perror(args[0]);
		return (STAY_LOOP);
	}
}

static int	within_range(char *str, int is_negative)
{
	unsigned long long	num;
	unsigned long long	max;
	int					digit;
	int					i;

	num = 0;
	max = LLONG_MAX;
	digit = 7;
	if (is_negative)
		digit = 8;
	i = 0;
	while (str[i])
	{
		if (num < max / 10 || (num == max / 10 && str[i] - '0' <= digit))
			num = num * 10 + (str[i] - '0');
		else
			return (0);
		i++;
	}
	return (1);
}

static int	is_numeric(char *str)
{
	int		is_negative;
	char	*head;
	char	*num;
	int		ret;

	is_negative = 0;
	str = ft_strtrim(str, " ");
	head = str;
	if (*str == '-' || *str == '+')
	{
		is_negative = (*str == '-' ? 1 : 0);
		str++;
	}
	if (!*str)
		return (0);
	num = str;
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	ret = within_range(num, is_negative);
	free(head);
	return (ret);
}

int			ft_exit(char **args)
{
	int	len;

	if (g_pid)
		ft_putendl_fd("exit", STDERR);
	if (args[1] && !ft_strcmp(args[1], "--"))
		args++;
	len = 0;
	while (args[len])
	{
		if (len == 1 && !is_numeric(args[len]))
			return (exit_error(args, len, E_NUMERIC));
		else if (len >= 2)
			return (exit_error(args, len, E_ARGS));
		len++;
	}
	if (len == 2)
		g_status = ft_atoi(args[1]);
	return (EXIT_LOOP);
}
