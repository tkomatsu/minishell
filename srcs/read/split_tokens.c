/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:30:29 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/16 15:20:30 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_metachar(char c)
{
	if (c == ' ' || c == '\t' || c == '\0')
		return (WORD);
	else if (c == '\n')
		return (NEWLINE);
	else if (c == '|')
		return (PIPE);
	else if (c == '&')
		return (AND);
	else if (c == ';')
		return (SEMICOLON);
	else if (c == '(')
		return (P_OPEN);
	else if (c == ')')
		return (P_CLOSE);
	else if (c == '>')
		return (GREATER);
	else if (c == '<')
		return (LESS);
	return (0);
}

int		get_index(char *line, int start)
{
	int	len;

	len = start;
	while (line[len])
	{
		if (line[len] == '\'')
		{
			len++;
			while (line[len] && line[len] != '\'')
				len++;
		}
		else if (line[len] == '\"')
		{
			len++;
			while (line[len] && line[len] != '\"')
				len++;
		}
		if (!line[len] || is_metachar(line[len]))
			break;
		len++;
	}
	return (len - start);
}

t_token	*split_tokens(char *line)
{
	t_token	*tokens;
	int		i;
	int		len;

	tokens = NULL;
	i = 0;
	while (line[i])
	{
		len = get_index(line, i);
		dlist_add_back(&tokens, dlistnew(ft_substr(line, i, len),
					is_metachar(line[i + len])));
		i = i + len + 1;
	}
	return (tokens);
}
