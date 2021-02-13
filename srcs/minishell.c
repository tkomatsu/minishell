/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:12:29 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/13 19:50:06 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**g_env;
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
	int			shlvl;

	envlen = 0;
	while (environ[envlen])
		envlen++;
	if (!(g_env = ft_calloc(envlen + 1, sizeof(char*))))
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
	shlvl = ft_atoi(ft_getenv("SHLVL")) + 1;
	ft_setenv("SHLVL", ft_itoa(shlvl), 1);
}

void	minish_loop()
{
	int		status;
	char	*line;
	t_token	*tokens;

	status = 1;
	while (status)
	{
		put_prompt();
		if (read_stdin(&line) == 1)
			continue;
		tokens = split_tokens(line);
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
	ft_putendl_fd("\nWELCOME TO MINISHELL\n", 2);
	minish_loop();
	ft_free_split(g_env);
	return (g_status);
}
