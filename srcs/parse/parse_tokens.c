/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:17:47 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/13 14:17:08 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parse_tokens(t_token *tokens)
{
	int		flag;
	char	*new;
	char	*str;

	flag = 0;
	new = ft_strdup("");
	str = tokens->word;
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
	ft_free(tokens->word);
	return (new);
}
