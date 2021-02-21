/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:30:29 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/21 20:59:11 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

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

static int	tokenlen(char *line, int start)
{
	int	end;

	end = start;
	while (line[end])
	{
		if (line[end] == '\'')
		{
			end++;
			while (line[end] && line[end] != '\'')
				end++;
		}
		else if (line[end] == '\"')
		{
			end++;
			while (line[end] && line[end] != '\"')
				end++;
		}
		if (is_metachar(line[end]))
			break ;
		end++;
	}
	return (end - start);
}

static void	remove_empty(t_token *token)
{
	t_token	*tmp;

	while (token)
	{
		if (*(token->word) == '\0' && token->type == WORD)
		{
			tmp = token->next;
			dlstextract(token);
			token = tmp;
		}
		else
			token = token->next;
	}
}

t_token		*tokenize(char *line)
{
	t_token	*tokens;
	int		i;
	int		len;

	tokens = NULL;
	i = 0;
	while (line[i])
	{
		len = tokenlen(line, i);
		dlist_add_back(
			&tokens,
			dlistnew(ft_substr(line, i, len), is_metachar(line[i + len])));
		i += len;
		if (line[i])
			i++;
	}
	remove_empty(tokens);
	return (tokens);
}
