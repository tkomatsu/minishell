/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 21:56:59 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/25 16:48:35 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void	del_token(t_token *token)
{
	if (token)
	{
		free(token->word);
		free(token);
	}
}
