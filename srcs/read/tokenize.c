/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:30:29 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/26 13:23:44 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

static int		is_metachar(char c)
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

static int		tokenlen(char *line, int start)
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

static t_token	*remove_empty(t_token *token)
{
	t_token	*tmp;
	t_token	*head;

	while (token)
	{
		if (!token->next)
			head = dlisthead(token);
		if (*(token->word) == '\0' && token->type == WORD)
		{
			tmp = token->next;
			dlstextract(token);
			token = tmp;
		}
		else
		{
			token = token->next;
		}
	}
	return (head);
}

static void		appending_redirect(t_token *token)
{
	t_token	*tmp;

	while (token)
	{
		if (token->type == GREATER)
		{
			if ((tmp = token->next) != NULL)
			{
				if (!(*tmp->word) && tmp->type == GREATER)
				{
					token->type = GREATER2;
					dlstextract(tmp);
				}
			}
		}
		token = token->next;
	}
}

t_token			*tokenize(char *line)
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
	appending_redirect(tokens);
	tokens = remove_empty(tokens);
	if (syntax_check(tokens))
	{
		clear_tokens(tokens);
		return (NULL);
	}
	return (tokens);
}
