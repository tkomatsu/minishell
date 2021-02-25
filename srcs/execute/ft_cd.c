/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:05:15 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/25 18:19:19 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static int	change_dir(char *dir)
{
	char	*path;
	char	*tmp;

	if (chdir(dir) < 0)
	{
		ft_putstr_fd("minish: cd: ", STDERR);
		ft_perror(dir);
		return (EXIT_FAILURE);
	}
	ft_setenv("OLDPWD", ft_getenv("PWD"), 1);
	if (!(path = getcwd(NULL, 0)))
	{
		ft_putstr_fd("cd: error retrieving current directory: ", STDERR);
		ft_putstr_fd("getcwd: cannot access parent directories: ", STDERR);
		ft_putstr_fd("No such file or directory\n", STDERR);
		tmp = ft_strjoin(ft_getenv("OLDPWD"), "/");
		path = ft_strjoin(tmp, dir);
		free(tmp);
	}
	ft_setenv("PWD", path, 1);
	free(path);
	return (EXIT_SUCCESS);
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
	g_status = change_dir(dir);
	return (STAY_LOOP);
}
