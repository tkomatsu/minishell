/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:05:15 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/28 21:25:12 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static int	change_dir(char *dir)
{
	char	*path;
	char	*tmp;
	int		has_pwd;

	has_pwd = 0;
	if (chdir(dir) < 0)
	{
		ft_putstr_fd("minish: cd: ", STDERR);
		ft_perror(dir);
		return (EXIT_FAILURE);
	}
	if (ft_getenv("PWD"))
		has_pwd = 1;
	ft_setenv("OLDPWD", ft_getenv("PWD"), 1);
	if (!(path = get_working_dir("cd")))
	{
		if (has_pwd)
			tmp = ft_strjoin(ft_getenv("OLDPWD"), "/");
		else
			tmp = ft_strdup("");
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
