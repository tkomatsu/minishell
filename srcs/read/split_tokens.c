/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:30:29 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/06 13:34:26 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_metachar(char c)
{
	if (c == ' ' || c == '\t')
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

/*
int	get_token(char **dst, char *src, int start)
{
	int		i;
	int		len;

	i = start;
	while (src[i])
	{
		if (src[i] == '\'')
			break;
//			return (squote(src, index));
		else if (src[i] == '\"')
			break;
//			return (dquote(src, index));
		i++;
	}
	len = i - start;
	if (!(*dst = ft_calloc(sizeof(char), (len + 1))))
		return (-1);
	ft_strlcpy(*dst, (src + i), len);
	return (i);
}

t_token	*split_tokens(char *line)
{
	t_token *tokens;
	char	*str;
	int		sep;
	int		i;

	i = 0;
	tokens = NULL;
	while (line[i])
	{
		i = get_token(&str, line, i);
		sep = is_metachar(line[i]);
		dlist_add_back(&tokens, dlistnew(str, sep));
	}
	return (dlisthead(tokens));
}
*/

t_token	*split_tokens(char *line)
{
	t_token	*tokens;

	tokens = NULL;
	dlist_add_back(&tokens, dlistnew(line, is_metachar(' ')));
	return (tokens);
}
