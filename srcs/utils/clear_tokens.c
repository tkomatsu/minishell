/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 21:56:59 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/09 00:57:15 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	del_token(t_token *token)
{
	if (token)
	{
		free(token->word);
		free(token);
		token = NULL;
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
	*tokens = NULL;
}
