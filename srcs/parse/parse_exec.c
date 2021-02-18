/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:35:03 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/18 17:07:38 by tkomatsu         ###   ########.fr       */
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

int	is_builtin(void *content)
{
	t_token		*token;
	const char	*builtin[] = {"cd", "env", "exit", "export", "unset", "echo", "pwd", NULL};
	int			i;

	token = content;
	i = 0;
	while (builtin[i])
		if (!ft_strcmp(builtin[i++], token->word))
			return (1);
	return (0);
}

int				parse_exec(t_token *tokens)
{
	t_list	*list_s;
	t_list	*list_p;
	int		status;

	status = 1;
	list_s = tokens_sep(tokens, SEMICOLON);
	while (list_s)
	{
		list_p = tokens_sep((t_token*)list_s->content, PIPE);
		ft_lstiter(list_s, parse_tokens);
		if (ft_lstsize(list_p) == 1 && is_builtin((list_p->content)))
			status = run_cmd(list_p->content, 0);
		else
			if (!(status = ft_lstiter_sta(list_p, run_cmd)))
				return (status);
		ft_lstclear(&list_p, NULL);
		list_s = list_s->next;
	}
	ft_lstclear(&list_s, NULL);
	return (status);
}