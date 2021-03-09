/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:05:15 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/03/09 12:50:42 by tkomatsu         ###   ########.fr       */
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

static int	many_arg(void)
{
	g_status = EX_EBUILTIN;
	ft_putendl_fd("minish: cd: too many arguments", STDERR);
	return (STAY_LOOP);
}

static char	*get_var(char *name)
{
	char	*dir;

	if (!(dir = ft_getenv(name)))
	{
		g_status = EXIT_FAILURE;
		ft_putstr_fd("minish: cd: ", STDERR);
		ft_putstr_fd(name, STDERR);
		ft_putendl_fd(" not set", STDERR);
	}
	return (dir);
}

int			ft_cd(int argc, char **argv)
{
	char	*dir;

	if (argc > 2)
		return (many_arg());
	if (!argv[1] || !ft_strcmp(argv[1], "~"))
	{
		if (!(dir = get_var("HOME")))
			return (STAY_LOOP);
	}
	else if (!ft_strcmp(argv[1], "-"))
	{
		if (!(dir = get_var("OLDPWD")))
			return (STAY_LOOP);
	}
	else
		dir = argv[1];
	if ((argc == 2 && *argv[1]) || argc == 1)
		g_status = change_dir(dir);
	return (STAY_LOOP);
}
