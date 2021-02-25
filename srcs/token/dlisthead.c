/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlisthead.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 22:16:31 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/24 23:38:03 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_token	*dlisthead(t_token *tokens)
{
	if (!tokens)
		return (NULL);
	if (!tokens->prev)
		return (tokens);
	return (dlisthead(tokens->prev));
}
