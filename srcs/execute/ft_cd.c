/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:05:15 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/21 16:08:24 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static void	change_dir(char *dir)
{
	ft_setenv("OLDPWD", ft_getenv("PWD"), 1);
	if (chdir(dir) < 0)
	{
		g_status = EXIT_FAILURE;
		ft_putstr_fd("minish: cd: ", STDERR);
		ft_perror(dir);
	}
	ft_setenv("PWD", getcwd(NULL, 0), 1);
}

int			ft_cd(char **args)
{
	char	*dir;

	if (!args[1] || !ft_strcmp(args[1], "~"))
	{
		if (!(dir = ft_getenv("HOME")))
		{
			g_status = EXIT_FAILURE;
			ft_putendl_fd("minish: cd: HOME not set", STDERR);
			return (STAY_LOOP);
		}
	}
	else if (!ft_strcmp(args[1], "-"))
	{
		if (!(dir = ft_getenv("OLDPWD")))
		{
			g_status = EXIT_FAILURE;
			ft_putendl_fd("minish: cd: OLDPWD not set", STDERR);
			return (STAY_LOOP);
		}
	}
	else
		dir = args[1];
	change_dir(dir);
	return (STAY_LOOP);
}
