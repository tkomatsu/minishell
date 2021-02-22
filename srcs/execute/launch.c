/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 22:52:44 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/22 15:27:33 by kefujiwa         ###   ########.fr       */
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

static char	*exec_path(char *cmd)
{
	char	*ret;
	char	**path;
	int		i;

	path = ft_split(ft_getenv("PATH"), ':');
	if (!path)
		return (NULL);
	i = 0;
	while (path[i])
	{
		if (is_exist(path[i], cmd))
		{
			cmd = ft_strjoin("/", cmd);
			ret = ft_strjoin(path[i], cmd);
			ft_free(cmd);
			ft_free_split(path);
			return (ret);
		}
		i++;
	}
	ft_free_split(path);
	return (NULL);
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
	char	*cmd_path;

	validate_cmd(args[0]);
	if ((cmd_path = exec_path(args[0])))
		args[0] = cmd_path;
	if (execve(args[0], args, g_env) == -1)
	{
		errno = E_CMD;
		ft_putstr_fd("minish: ", STDERR);
		ft_perror(args[0]);
	}
	ft_free(cmd_path);
	return (STAY_LOOP);
}
