/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_words.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 03:12:38 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/04 01:14:21 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	words_to_tokens(char *new, char *str, char **ptr, t_token *tokens)
{
	char	**words;
	char	*tmp;

	while (*new && *new != ' ')
		new++;
	if (!*new)
	{
		*ptr = str;
		return ;
	}
	*(new++) = '\0';
	if (!(words = ft_split(new, ' ')))
		exit_perror("convert_words", EXIT_FAILURE);
	while (*words)
	{
		dlist_insert(tokens, dlistnew(*words, WORD));
		tokens = tokens->next;
		words++;
	}
	if (!(tmp = ft_strdup(str)))
		exit_perror("convert_words", EXIT_FAILURE);
	dlist_insert(tokens, dlistnew(tmp, WORD));
	**ptr = '\0';
}

static char	*convert_escape(char *new, char *str)
{
	char	*ret;
	char	*tmp;
	int		i;

	ret = NULL;
	tmp = NULL;
	if (!str || !(tmp = ft_strjoin(new, str)))
		exit_perror("convert_escape", EXIT_FAILURE);
	free(new);
	free(str);
	if (!(ret = ft_calloc(ft_strlen(tmp) + 1, sizeof(char))))
		exit_perror("convert_escape", EXIT_FAILURE);
	i = 0;
	new = tmp;
	while (*tmp)
	{
		if (*tmp == '\\')
			tmp++;
		ret[i++] = *tmp;
		if (*tmp)
			tmp++;
	}
	free(new);
	return (ret);
}

char		*convert_words(char *str, char **ptr, t_token *tokens)
{
	char	*new;
	char	*head;
	int		flag;

	new = NULL;
	head = str;
	flag = 0;
	while (!(*str == '\'' || *str == '\"' || *str == '\0')
			|| ((*str == '\'' || *str == '\"') && (flag & ESC)))
	{
		if (*str == '$' && !(flag & ESC))
		{
			*str = '\0';
			if (*(str + 1) == '\"' || *(str + 1) == '\'')
			{
				str++;
				break ;
			}
			new = expand_environ(str + 1, new, &head, &str);
		}
		validate_escape(*(str++), &flag);
	}
	new = convert_escape(new, ft_substr(head, 0, str - head));
	words_to_tokens(new, str, ptr, tokens);
	return (new);
}
