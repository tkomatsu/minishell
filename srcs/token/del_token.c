/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 21:56:59 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/24 23:40:26 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void	del_token(t_token *token)
{
	if (token)
	{
		ft_free(token->word);
		ft_free(token);
	}
}
