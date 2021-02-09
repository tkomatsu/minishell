/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:35:03 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/09 13:41:53 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*tokens_sep(t_token *tokens, int type)
{
	t_list	*list;

	list = NULL;
	while (tokens)
	{
		if (!(tokens->prev))
			ft_lstadd_back(&list, ft_lstnew(tokens));
		else if (tokens->prev->type == type)
		{
			tokens->prev->next = NULL;
			tokens->prev = NULL;
			ft_lstadd_back(&list, ft_lstnew(tokens));
		}
		tokens = tokens->next;
	}
	return (list);
}

static char		**convert_lst_to_args(t_token *tokens)
{
	char	**args;
	int		i;

	/* environment viriable */
	/* redirect */
	/* escape */

	if (!(args = ft_calloc(sizeof(char**), token_size(tokens) + 1)))
		return NULL;
	i = 0;
	while (tokens)
	{
		if (tokens && *(tokens->word))
			args[i++] = tokens->word;
		tokens = tokens->next;
	}
	return (args);
}

int				parse_exec(t_token *tokens)
{
	t_list	*list_s;
	t_list	*list_p;
	char	**args;
	int		status;

	status = 1;
	list_s = tokens_sep(tokens, SEMICOLON);
	while (list_s)
	{
		list_p = tokens_sep((t_token*)list_s->content, PIPE);
		while (list_p)
		{
			/* fork() */
			args = convert_lst_to_args((t_token*)list_p->content);
			status = execmd(args);
			ft_free(args);
			list_p = list_p->next;
		}
		ft_lstclear(&list_p, ft_free);
		list_s = list_s->next;
	}
	ft_lstclear(&list_s, ft_free);
	return (status);
}