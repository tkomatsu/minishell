/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:12:29 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/20 19:47:11 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**g_env;

int		split_exec(char *line)
{
	char	**cmds;
	char	**args;
	int		i;
	int		status;

	cmds = ft_split(line, ';');
	i = 0;
	while (cmds[i])
	{
		args = ft_split(cmds[i], ' ');
		status = execmd(args);
		ft_free_split(args);
		i++;
	}
	ft_free_split(cmds);
	return (status);
}

void	ft_envcpy(void)
{
	extern char	**environ;
	int			i;
	int			envlen;

	envlen = 0;
	while (environ[envlen])
		envlen++;
	if (!(g_env = ft_calloc(sizeof(char*), envlen + 1)))
	{
		perror("envcpy");
		exit(1);
	}
	i = 0;
	while (environ[i])
	{
		if (!(g_env[i] = ft_strdup(environ[i])))
		{
			perror("envcpy");
			exit(1);
		}
		i++;
	}
}

void	minish_loop(void)
{
	char	*line;
	int		status;

	status = 1;
	while (status)
	{
		ft_putstr_fd("> ", 1);
		read_arg(&line);
		status = split_exec(line);
		ft_free(line);
	}
}

int		main(void)
{
	ft_envcpy();
	ft_putendl_fd("\nWELCOME TO MINISHELL\n", 1);
	minish_loop();
	ft_free_split(g_env);
	return (EXIT_SUCCESS);
}
