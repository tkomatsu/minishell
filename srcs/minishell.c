/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:12:29 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/19 21:11:23 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char	**ft_envcpy(void)
{
	extern char	**environ;
	int			i;
	int			envlen;
	char		**ft_env;

	envlen = 0;
	while (environ[envlen])
		envlen++;
	if (!(ft_env = ft_calloc(sizeof(char*), envlen + 1)))
	{
		perror("envcpy");
		exit(1);
	}
	i = 0;
	while (environ[i])
	{
		if (!(ft_env[i] = ft_strdup(environ[i])))
		{
			perror("envcpy");
			exit(1);
		}
		i++;
	}
	return (ft_env);
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
	char	**env;

	env = ft_envcpy();
	ft_putendl_fd("\nWELCOME TO MINISHELL\n", 1);
	minish_loop();
	ft_free_split(env);
	return (EXIT_SUCCESS);
}
