/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:17:47 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/12 19:47:43 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*parse_words(char *str)
{
	char	*new;

	new = ft_strdup("");
	if (*str == '\'')
		str = convert_quotes(str + 1, &new);
	else if (*str == '\"')
		str = convert_dquotes(str + 1, &new);
	else
		str = convert_words(str, &new);
	if (!str)
		return (NULL);
	while(*str)
	{
		if (*str == '\'' && *(str - 1) != '\\')
			str = convert_quotes(str + 1, &new);
		else if (*str == '\"' && *(str - 1) != '\\')
			str = convert_dquotes(str + 1, &new);
		else
			str = convert_words(str, &new);
		if (!str)
			return (NULL);
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
