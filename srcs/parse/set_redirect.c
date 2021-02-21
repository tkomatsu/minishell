/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 23:16:39 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/21 13:54:32 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	output_redirect(t_token *token);

void	set_redirect(t_token *token)
{
	while (token)
	{
		if (token->type == LESS)
			input_redirect(token);
		/*
		else if (token->type == GREATER)
			output_redirect(token);
		*/
		token = token->next;
	}
}
