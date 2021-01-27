/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:12:29 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/27 13:08:46 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**g_env;

void	test_tokens(t_list *tokens)
{
	t_token	*token;

	for (int i = 0; tokens; i++)
	{
		token = (t_token*)tokens->content;
		printf("[%2d]%s\n", i, token->word);
		tokens = tokens->next;
	}
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
	int		status;
	char	*line;
	t_list	*tokens;

	status = 1;
	while (status)
	{
		ft_putstr_fd("> ", 1);
		read_stdin(&line);
		tokens = split_tokens(line);
		test_tokens(tokens);
		//status = parse_exec(tokens);
		ft_free(line);
		ft_lstclear(&tokens, del_token);
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
