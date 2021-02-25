/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlistnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 22:16:31 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/24 23:38:12 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_token	*dlistnew(char *src, int sep)
{
	t_token	*new;

	if (!(new = ft_calloc(1, sizeof(t_token))))
		exit_perror("dlistnew", EXIT_FAILURE);
	new->word = src;
	new->type = sep;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
