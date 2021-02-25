/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 22:52:44 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/25 17:27:09 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static int	is_exist(char *path, char *cmd)
{
	DIR				*dir;
	struct dirent	*dent;

	if (!(dir = opendir(path)))
		return (0);
	while ((dent = readdir(dir)))
		if (!strcmp(cmd, dent->d_name))
			return (1);
	closedir(dir);
	return (0);
}

static int	exec_item(char *item, char *cmd, char **args)
{
	char	*ret;
	char	*tmp;

	if (is_exist(item, cmd))
	{
		tmp = ft_strjoin("/", cmd);
		ret = ft_strjoin(item, tmp);
		free(tmp);
		if (!execve(ret, args, g_env))
		{
			free(ret);
			return (1);
		}
		free(ret);
	}
	return (0);
}

static int	exec_path(char *cmd, char **args)
{
	char	**path;
	int		i;

	path = ft_split(ft_getenv("PATH"), ':');
	if (!path)
		return (0);
	i = 0;
	while (path[i])
	{
		if (exec_item(path[i], cmd, args))
		{
			ft_free_split(path);
			return (1);
		}
		i++;
	}
	ft_free_split(path);
	return (0);
}

static void	validate_cmd(char *path)
{
	struct stat	st;

	if (!ft_strchr(path, '/'))
		return ;
	if ((lstat(path, &st) < 0))
	{
		ft_putstr_fd("minish: ", STDERR);
		if (errno == ENOTDIR)
			exit_perror(path, EX_EPERM);
		else if (errno == ENOENT)
			exit_perror(path, EX_ENOENT);
		else if (errno == EACCES)
			exit_perror(path, EXIT_FAILURE);
	}
	if (S_ISDIR(st.st_mode))
	{
		errno = EISDIR;
		ft_putstr_fd("minish: ", STDERR);
		exit_perror(path, EX_EPERM);
	}
}

int			launch(char **args)
{
	int	is_error;

	is_error = 0;
	validate_cmd(args[0]);
	if (!exec_path(args[0], args))
	{
		if (execve(args[0], args, g_env) == -1)
		{
			is_error = 1;
			errno = E_CMD;
			ft_putstr_fd("minish: ", STDERR);
			ft_perror(args[0]);
			g_status = EX_ENOENT;
		}
	}
	if (!is_error)
		g_status = EXIT_SUCCESS;
	return (STAY_LOOP);
}
