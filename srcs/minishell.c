/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:12:29 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/22 17:38:58 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**g_env;
pid_t	g_pid;
int		g_status;

void	ft_envcpy(void)
{
	extern char	**environ;
	int			i;
	int			envlen;
	static int	shlvl = 1;

	envlen = 0;
	while (environ[envlen])
		envlen++;
	if (!(g_env = ft_calloc(envlen + 1, sizeof(char*))))
		exit_perror("envcpy", EXIT_FAILURE);
	i = 0;
	while (environ[i])
	{
		if (!(g_env[i] = ft_strdup(environ[i])))
			exit_perror("envcpy", EXIT_FAILURE);
		i++;
	}
	if (ft_getenv("SHLVL"))
		shlvl = ft_atoi(ft_getenv("SHLVL")) + 1;
	ft_setenv("SHLVL", ft_itoa(shlvl), 1);
	ft_setenv("PWD", getcwd(NULL, 0), 1);
	ft_setenv("OLDPWD", NULL, 1);
}

void	minish_loop(void)
{
	int		status;
	char	*line;
	t_token	*tokens;

	status = STAY_LOOP;
	while (status)
	{
		g_pid = 0;
		signal(SIGINT, signal_handler);
		signal(SIGQUIT, signal_handler);
		put_prompt("PS1");
		if (read_stdin(&line) == INVALID_INPUT)
			continue;
		tokens = tokenize(line);
		status = parse_exec(tokens);
		ft_free(line);
		clear_tokens(&tokens);
	}
}

int		main(void)
{
	ft_envcpy();
	g_status = EXIT_SUCCESS;
	ft_putendl_fd("\nWELCOME TO MINISHELL\n", STDERR);
	minish_loop();
	ft_free_split(g_env);
	return ((unsigned char)g_status);
}
