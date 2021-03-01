/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 23:16:39 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/03/01 19:17:17 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int			set_redirect(t_token *token)
{
	int	status;

	status = 0;
	while (token)
	{
		if (token->type == LESS || token->type == GREATER ||
			token->type == GREATER2)
			if ((status = io_redirect(token)) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		token = token->next;
	}
	return (EXIT_SUCCESS);
}
