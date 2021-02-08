/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 01:37:45 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/09 01:45:18 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
