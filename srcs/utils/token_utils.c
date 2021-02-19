/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 22:16:31 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/19 23:50:08 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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

t_token	*dlisthead(t_token *tokens)
{
	if (!tokens)
		return (NULL);
	if (!tokens->prev)
		return (tokens);
	return (dlisthead(tokens->prev));
}

t_token	*dlistlast(t_token *tokens)
{
	if (!tokens)
		return (NULL);
	if (!tokens->next)
		return (tokens);
	return (dlistlast(tokens->next));
}

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
