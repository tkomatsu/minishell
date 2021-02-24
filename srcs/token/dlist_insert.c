/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 00:27:47 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/25 00:35:45 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void	dlist_insert(t_token *tokens, t_token *new)
{
	t_token *tmp;

	if (!tokens || !new)
		return ;
	tmp = tokens->next;
	tokens->next = new;
	new->prev = tokens;
	new->next = tmp;
	if (new->next)
		new->next->prev = new;
}
