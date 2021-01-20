/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:11:50 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/20 20:59:06 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_env(void)
{
	int			i;

	i = 0;
	while (g_env[i])
		ft_putendl_fd(g_env[i++], 1);
	return (1);
}

int	msh_export(char **args)
{
	ft_putenv(args[1]);
	return (1);
}

int	msh_unset(char **args)
{
	int	i;

	i = 1;
	while (args[i])
		ft_unsetenv(args[i++]);
	return (1);
}
