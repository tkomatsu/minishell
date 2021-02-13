/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 23:25:58 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/13 19:54:45 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	export_list()
{
	int	i;

	i = 0;
	while (g_env[i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putendl_fd(g_env[i++], 1);
	}
}

int	msh_export(char **args)
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
			errno = 203;
			ft_putstr_fd("minish: export: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd("'", 2);
			ft_perror("");
		}
		i++;
	}
	return (1);
}
