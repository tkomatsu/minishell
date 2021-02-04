/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:30:29 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/04 22:17:04 by tkomatsu         ###   ########.fr       */
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

int		get_token(char **dst, char *src, int *index);

t_token	*split_tokens(char *line)
{
	t_token *head;
	char	*str;
	int		sep;
	int		i;

	i = 0;
	while (line[i])
	{
		sep = get_token(&str, line, &i);
		dlist_add_back(&head, dlistnew(str, sep));
		i++;
	}
	return (head);
}
