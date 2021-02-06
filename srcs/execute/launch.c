/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 22:52:44 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/06 10:21:17 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_exist(char *path, char *cmd)
{
	DIR				*dir;
	struct dirent	*dent;

	if (!(dir = opendir(path)))
		return (0);
	while ((dent = readdir(dir)))
		if (!strcmp(cmd, dent->d_name))
			return (1);
	return (0);
}

char	*exec_path(char *cmd)
{
	char	*ret;
	char	**path;
	int		i;

	path = ft_split(ft_getenv("PATH"), ':');
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

int	launch(char **args)
{
	pid_t		pid;
	int			status;
	char		*cmd_path;

	pid = fork();
	if (!pid)
	{
		if ((cmd_path = exec_path(args[0])))
			args[0] = cmd_path;
		if (execve(args[0], args, g_env) == -1)
		{
			errno = 201;
			ft_putstr_fd("minish: ", 2);
			ft_perror(args[0]);
		}
		ft_free(cmd_path);
		exit(1);
	}
	else if (pid < 0)
		perror("fork");
	else
	{
		if (wait(&status) < 0)
		{
			perror("wait");
			exit(1);
		}
	}
	return (1);
}
