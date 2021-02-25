/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 22:16:31 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/24 23:38:54 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void	dlist_add_back(t_token **list, t_token *new)
{
	t_token	*end;

	if (!list || !new)
		return ;
	if (!(*list))
		*list = new;
	else
	{
		end = dlistlast(*list);
		end->next = new;
		new->prev = end;
	}
}
