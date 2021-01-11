/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 22:52:44 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/11 12:54:13 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**g_env;

int	launch(char **args)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (!pid)
	{
		if (execve(args[0], args, g_env) == -1)
			perror("minish");
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
