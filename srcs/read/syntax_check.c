/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:06:41 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/24 12:40:12 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

int	syntax_check(t_token *token)
{
	const char	*type;

	type = "  |&;{}>><";
	while (token)
	{
		if (token->type != WORD && token->next && token->type == token->next->type)
		{
			ft_putstr_fd("minish: syntax error near unexpected token `", STDERR);
			ft_putchar_fd(type[token->type - 1], STDERR);
			ft_putstr_fd("\'\n", STDERR);
			return (1);
		}
		if ((token->type == GREATER || token->type == GREATER2) && token->next &&
			(token->next->type == GREATER || token->next->type == GREATER2))
		{
			ft_putstr_fd("minish: syntax error near unexpected token `", STDERR);
			ft_putchar_fd(type[token->type - 1], STDERR);
			ft_putstr_fd("\'\n", STDERR);
			return (1);
		}
		token = token->next;
	}
	return (0);
}
