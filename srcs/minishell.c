/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:12:29 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/21 02:38:57 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**g_env;
pid_t	g_pid;
int		g_status;

void	test_tokens(t_token *tokens)
{
	char type[10][20] = {"word", "newline", "pipe", "and", "semicolon", "p_open", "p_close", "greater", "less"};

	for (int i = 0; tokens; i++)
	{
		printf("[%2d]%s, type:%s\n", i, tokens->word, type[(tokens->type - 1)]);
		tokens = tokens->next;
	}
}

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
		put_prompt();
		if (read_stdin(&line) == INVALID_INPUT)
			continue;
		tokens = tokenize(line);
		/* test_tokens(tokens); */
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
