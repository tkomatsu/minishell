/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 21:56:59 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/18 19:36:47 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	del_token(t_token *token)
{
	if (token)
	{
		ft_free(token->word);
		ft_free(token);
	}
}

void		clear_tokens(t_token **tokens)
{
	t_token	*now;
	t_token	*next;

	now = *tokens;
	while (now)
	{
		next = now->next;
		del_token(now);
		now = next;
	}
	tokens = NULL;
}
