/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 22:16:31 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/06 11:59:35 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

t_token	*dlistnew(char *src, int sep)
{
	t_token	*new;

	new = ft_calloc(sizeof(t_token), 1);
	new->word = src;
	new->type = sep;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_token *dlisthead(t_token *tokens)
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
