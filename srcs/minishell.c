/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:12:29 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/03/01 19:33:24 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**g_env;
pid_t		g_pid;
int			g_status;

static void	set_shlvl(void)
{
	int		shlvl;
	char	*level;

	shlvl = ft_atoi(ft_getenv("SHLVL")) + 1;
	if (shlvl < 0)
		ft_setenv("SHLVL", "0", 1);
	else if (shlvl == 1000)
		ft_setenv("SHLVL", "", 1);
	else if (shlvl > 1000)
	{
		ft_putstr_fd("minish: warning: shell level (", STDERR);
		ft_putnbr_fd(shlvl, STDERR);
		ft_putendl_fd(") too high, resetting to 1", STDERR);
		ft_setenv("SHLVL", "1", 1);
	}
	else
	{
		level = ft_itoa(shlvl);
		ft_setenv("SHLVL", level, 1);
		free(level);
	}
}

static void	ft_envcpy(void)
{
	extern char	**environ;
	int			i;
	int			envlen;

	envlen = 0;
	while (environ[envlen])
		envlen++;
	if (!(g_env = ft_calloc(envlen + 1, sizeof(char *))))
		exit_perror("envcpy", EXIT_FAILURE);
	i = 0;
	while (environ[i])
	{
		if (!(g_env[i] = ft_strdup(environ[i])))
			exit_perror("envcpy", EXIT_FAILURE);
		i++;
	}
}

static void	empty_env(void)
{
	char	*tmp;

	if (ft_getenv("SHLVL"))
		set_shlvl();
	else
		ft_setenv("SHLVL", "1", 1);
	tmp = getcwd(NULL, 0);
	if (!ft_getenv("PWD"))
		ft_setenv("PWD", tmp, 1);
	if (!ft_getenv("OLDPWD"))
		ft_setenv("OLDPWD", NULL, 1);
	free(tmp);
}

static void	minish_loop(void)
{
	int		status;
	char	*line;
	t_token	*tokens;

	status = STAY_LOOP;
	while (status)
	{
		g_pid = INITIAL;
		signal(SIGINT, signal_handler);
		signal(SIGQUIT, signal_handler);
		put_prompt("PS1");
		if (read_stdin(&line) == INVALID_INPUT)
			continue ;
		if (!*line || !(tokens = tokenize(line)))
		{
			free(line);
			continue ;
		}
		free(line);
		status = parse_exec(tokens);
	}
}

int			main(void)
{
	ft_envcpy();
	empty_env();
	g_status = EXIT_SUCCESS;
	g_sigint = OFF;
	minish_loop();
	ft_free_split(g_env);
	return ((unsigned char)g_status);
}
