/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:30:29 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/26 18:07:42 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_metachar(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '|' || c == '&'
			|| c == ';' || c == '(' || c == ')' || c == '>' || c == '<')
		return (1);
	return (0);
}

void	split_tokens(t_list **tokens, char *line)
{
	char	*meta;
	t_token	*token;

	meta = line;
	if (!(token = ft_calloc(sizeof(t_token), 1)))
		return;
	while (!is_metachar(*meta))
		meta++;
	if (*meta == ' ')
		token->metachar = SPACE;
	*meta = '\0';
	token->word = ft_strdup(line);
	ft_lstadd_back(tokens, ft_lstnew((void*)token));
	split_tokens(tokens, meta + 1);
}

t_list	*read_tokens(void)
{
	char	*line;
	t_list	*tokens;

	read_arg(&line);
	split_tokens(&tokens, line);
	return (tokens);
}
