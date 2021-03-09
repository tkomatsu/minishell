/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:06:41 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/03/09 15:25:34 by tkomatsu         ###   ########.fr       */
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

static int	istype(t_token *token, int type)
{
	if (token->type == type)
		return (1);
	return (0);
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
		if (!istype(token, WORD) && token->next && !*(token->next->word))
		{
			if (!istype(token->next, GREAT)
					&& !istype(token->next, DGREAT)
					&& !istype(token->next, LESS))
				return (put_err(token));
		}
		token = token->next;
	}
	return (0);
}
