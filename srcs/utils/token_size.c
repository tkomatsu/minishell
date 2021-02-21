/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 01:37:45 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/21 21:00:58 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

int	token_size(t_token *tokens)
{
	int	cnt;

	cnt = 0;
	while (tokens)
	{
		cnt++;
		tokens = tokens->next;
	}
	return (cnt);
}
