/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 23:25:58 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/19 14:23:36 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static void	export_list(void)
{
	int		i;
	char	*item;

	i = 0;
	while ((item = g_env[i++]))
	{
		ft_putstr_fd("declare -x ", STDOUT);
		while (*item && *item != '=')
			ft_putchar_fd(*(item++), STDOUT);
		if (*(item++) == '=')
			ft_putstr_fd("=\"", STDOUT);
		else
		{
			ft_putchar_fd('\n', STDOUT);
			continue ;
		}
		while (*item)
		{
			if (*item == '$' || *item == '`' || *item == '\\' || *item == '"')
				ft_putchar_fd('\\', STDOUT);
			ft_putchar_fd(*(item++), STDOUT);
		}
		ft_putstr_fd("\"\n", STDOUT);
	}
}

int			ft_export(char **args)
{
	int	i;

	i = 1;
	if (!args[i])
		export_list();
	while (args[i])
	{
		if (ft_putenv(args[i]) == -1)
		{
			g_status = EXIT_FAILURE;
			errno = E_VALID;
			ft_putstr_fd("minish: export: `", STDERR);
			ft_putstr_fd(args[i], STDERR);
			ft_putstr_fd("'", STDERR);
			ft_perror("");
		}
		i++;
	}
	return (1);
}
