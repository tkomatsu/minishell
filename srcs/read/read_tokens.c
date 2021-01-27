/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:30:29 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/27 09:06:29 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_metachar(char c)
{
	if (c == ' ')
		return (SPACE);
	else if (c == '\t')
		return (TAB);
	else if (c == '\n')
		return (NEWLINE);
	else if (c == '|')
		return (PIPE);
	else if (c == '&')
		return (AMPERSAND);
	else if (c == ';')
		return (SEMICOLON);
	else if (c == '(')
		return (P_BEGIN);
	else if (c == ')')
		return (P_END);
	else if (c == '>')
		return (GREATER);
	else if (c == '<')
		return (LESS);
	else if (c == '\0')
		return (-1);
	return (0);
}

void	split_tokens(t_list **tokens, char *line)
{
	int	begin;
	int	end;
	t_token	*new;

	begin = 0;
	end = 0;
	while (line[begin])
	{
		if (!(new = ft_calloc(sizeof(t_token), 1)))
			return;
		while (!(new->metachar = is_metachar(line[end])))
			end++;
		line[end] = '\0';
		new->word = ft_strdup(&line[begin]);
		ft_lstadd_back(tokens, ft_lstnew(new));
		if (new->metachar < 0)
			break;
		else
			begin = end + 1;
	}
}

/*
void	split_tokens(t_list **tokens, char *line)
{
	char	*meta;
	t_token	*token;

	if (!(*line))
		return;
	meta = line;
	if (!(token = ft_calloc(sizeof(t_token), 1)))
		return;
	while (!is_metachar(*meta))
		meta++;
	if (*meta == ' ')
		token->metachar = SPACE;
	*meta = '\0';
	token->word = ft_strdup(line);
	ft_lstadd_back(tokens, ft_lstnew(token));
	if (*(meta + 1))
		split_tokens(tokens, meta + 1);
}
*/

t_list	*read_tokens(void)
{
	char	*line;
	t_list	*tokens;

	read_arg(&line);
	ft_lstclear(&tokens, del_token);
	split_tokens(&tokens, line);
	return (tokens);
}
