/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:06:41 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/03/08 16:17:49 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

static int	put_err(t_token *token)
{
	const char	*type;

	type = "  |&;{}>><";
	ft_putstr_fd("minish: syntax error near unexpected token `", STDERR);
	ft_putchar_fd(type[token->type - 1], STDERR);
	ft_putstr_fd("\'\n", STDERR);
	g_status = EX_EBUILTIN;
	return (1);
}

int			syntax_check(t_token *token)
{
	if (!token)
		return (1);
	if (*token->word == '\0' &&
			(token->type == SEMICOLON || token->type == PIPE))
		return (put_err(token));
	while (token)
	{
		if (token->type != WORD && token->next && !*token->next->word
				&& token->type == token->next->type)
			return (put_err(token));
		if ((token->type == GREATER || token->type == GREATER2) && token->next
				&& !*token->next->word
				&& (token->next->type == GREATER
					|| token->next->type == GREATER2))
			return (put_err(token));
		token = token->next;
	}
	return (0);
}
