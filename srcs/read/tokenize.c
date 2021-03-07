/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:30:29 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/03/07 09:33:37 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

static int		is_metachar(char c)
{
	if (c == ' ' || c == '\t' || c == '\0')
		return (WORD);
	else if (c == '|')
		return (PIPE);
	else if (c == ';')
		return (SEMICOLON);
	else if (c == '>')
		return (GREATER);
	else if (c == '<')
		return (LESS);
	return (0);
}

static int		tokenlen(char *line, int begin)
{
	int	i;
	int	flag;

	i = begin;
	flag = 0;
	while (line[i])
	{
		if (line[i] == '\\' && !(flag & QUOTE))
		{
			if (line[++i])
				i++;
			continue ;
		}
		if (is_metachar(line[i]) && !flag)
			break ;
		if (line[i] == '\'')
			flag ^= QUOTE;
		else if (line[i] == '\"')
			flag ^= DQUOTE;
		i++;
	}
	return (i - begin);
}

static t_token	*remove_empty(t_token *token)
{
	t_token	*tmp;
	t_token	*head;
	int		flag;

	flag = 0;
	while (token)
	{
		if (!token->next)
			head = dlisthead(token);
		if (!ft_strcmp(token->word, "") && token->type == WORD)
		{
			tmp = token->next;
			dlstextract(token);
			token = tmp;
		}
		else
		{
			flag = 1;
			token = token->next;
		}
	}
	if (flag)
		return (head);
	return (NULL);
}

static void		appending_redirect(t_token *token)
{
	t_token	*tmp;

	while (token)
	{
		if (token->type == GREATER)
		{
			if ((tmp = token->next) != NULL)
			{
				if (!(*tmp->word) && tmp->type == GREATER)
				{
					token->type = GREATER2;
					dlstextract(tmp);
				}
			}
		}
		token = token->next;
	}
}

t_token			*tokenize(char *line)
{
	t_token	*tokens;
	int		i;
	int		len;

	tokens = NULL;
	i = 0;
	while (line[i])
	{
		len = tokenlen(line, i);
		dlist_add_back(
			&tokens,
			dlistnew(ft_substr(line, i, len), is_metachar(line[i + len])));
		i += len;
		if (line[i])
			i++;
	}
	appending_redirect(tokens);
	tokens = remove_empty(tokens);
	if (syntax_check(tokens))
	{
		clear_tokens(tokens);
		return (NULL);
	}
	return (tokens);
}

/*
** int	main(int ac, char **av)
** {
** 	int len;
** 	char *str;
** 	int start;
** 
** 	if (ac != 3)
** 	{
** 		printf("Need args!\n");
** 		return (1);
** 	}
** 	start = ft_atoi(av[2]);
** 	len = tokenlen(av[1], start);
** 	str = ft_substr(av[1], start, len);
** 	ft_putendl_fd(av[1], 1);
** 	ft_putstr_fd("len: ", 1);
** 	ft_putnbr_fd(len, 1);
** 	ft_putstr_fd("strlen: ", 1);
** 	ft_putnbr_fd(ft_strlen(str), 1);
** 	ft_putstr_fd(", str: ", 1);
** 	ft_putendl_fd(str, 1);
** 	return (0);
** }
*/
