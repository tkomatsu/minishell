/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:35:03 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/09 02:41:54 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*tokens_sep(t_token *tokens, int type)
{
	t_token	*tmp;
	t_list	*list;

	list = NULL;
	if (tokens)
		ft_lstadd_back(&list, ft_lstnew(tokens));
	while (tokens)
	{
		if (tokens->type == type && tokens->next)
		{
			ft_lstadd_back(&list, ft_lstnew(tokens->next));
			tmp = tokens->next;
			tokens->next = NULL;
			tokens = tmp;
		}
		else
			tokens = tokens->next;
	}
	return (list);
}

static char		**convert_lst_to_args(t_token *tokens)
{
	char	**args;
	int		i;

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
			args = convert_lst_to_args((t_token*)list_p->content);
			status = execmd(args);
			free(args);
			list_p = list_p->next;
		}
		ft_lstclear(&list_p, ft_free);
		list_s = list_s->next;
	}
	ft_lstclear(&list_s, ft_free);
	return (status);
}
