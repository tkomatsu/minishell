/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:17:47 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/13 00:35:21 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*parse_words(char *str)
{
	int		flag;
	char	*new;

	flag = 0;
	new = ft_strdup("");
	while(*str)
	{
		if (*str == '\'' && !flag)
			str = convert_quotes(str + 1, &new);
		else if (*str == '\"' && !flag)
			str = convert_dquotes(str + 1, &new);
		else
			str = convert_words(str, &new);
		if (!str)
			return (NULL);
		if (*str == '\\')
			flag ^= ESC;
		else
			flag = 0;
	}
	return (new);
}

void		parse_tokens(t_token *tokens)
{
	char	*tmp;

	tmp = parse_words(tokens->word);
	ft_free(tokens->word);
	tokens->word = tmp;
}
