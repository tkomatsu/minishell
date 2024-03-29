/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 21:56:59 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/25 17:59:19 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void	clear_tokens(void *tokens)
{
	t_token	*now;
	t_token	*next;

	now = tokens;
	while (now)
	{
		next = now->next;
		del_token(now);
		now = next;
	}
	tokens = NULL;
}
