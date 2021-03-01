/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:05:15 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/03/01 16:35:09 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static void	set_cwd(char *dir)
{
	char	*path;
	char	*tmp;
	char	**dest;
	int		i;

	dest = ft_split(dir, '/');
	path = ft_strdup(ft_getenv("PWD"));
	i = 0;
	while (dest[i])
	{
		if (!ft_strcmp(dest[i], ".."))
		{
			tmp = ft_strrchr(path, '/');
			*tmp = 0;
		}
		else if (ft_strcmp(dest[i], "."))
		{
			tmp = ft_strjoin(path, "/");
			free(path);
			path = ft_strjoin(tmp, dest[i]);
		}
		i++;
	}
	ft_setenv("PWD", path, 1);
	ft_free_split(dest);
	free(path);
}

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
	if (!(path = get_working_dir("cd")))
	{
		if (!ft_getenv("PWD"))
			path = ft_strdup(dir);
		else
		{
			tmp = ft_strjoin(ft_getenv("PWD"), "/");
			path = ft_strjoin(tmp, dir);
			free(tmp);
		}
		ft_setenv("OLDPWD", ft_getenv("PWD"), 1);
		ft_setenv("PWD", path, 1);
		free(path);
	}
	if (*dir == '/')
		ft_setenv("PWD", dir, 1);
	else
		set_cwd(dir);
	return (EXIT_SUCCESS);
}

int			ft_cd(char **args)
{
	char	*dir;

	if (!args[1])
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
