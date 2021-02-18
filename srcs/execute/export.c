/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 23:25:58 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/19 02:55:15 by kefujiwa         ###   ########.fr       */
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
		ft_putstr_fd("declare -x ", 1);
		while (*item && *item != '=')
			ft_putchar_fd(*(item++), 1);
		if (*(item++) == '=')
			ft_putstr_fd("=\"", 1);
		else
		{
			ft_putchar_fd('\n', 1);
			continue ;
		}
		while (*item)
		{
			if (*item == '$' || *item == '`' || *item == '\\' || *item == '"')
				ft_putchar_fd('\\', 1);
			ft_putchar_fd(*(item++), 1);
		}
		ft_putstr_fd("\"\n", 1);
	}
}

int			msh_export(char **args)
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
			ft_putstr_fd("minish: export: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd("'", 2);
			ft_perror("");
		}
		i++;
	}
	return (1);
}
