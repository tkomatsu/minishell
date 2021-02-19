/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:17:47 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/19 14:19:45 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static char	*strjoin_free(char *new, char *str, int type)
{
	char	*ret;

	if (!str)
		return (NULL);
	if (!(ret = ft_strjoin(new, str)))
		return (NULL);
	if (type != QUOTE)
		ft_free(str);
	ft_free(new);
	return (ret);
}

void		exp_word(void *content)
{
	t_token	*tokens;
	int		flag;
	char	*new;
	char	*str;

	tokens = (t_token*)content;
	flag = 0;
	new = ft_strdup("");
	str = tokens->word;
	while (*str)
	{
		if (*str == '\'' && !flag)
			new = strjoin_free(new, convert_quotes(str + 1, &str), T_QUOTE);
		else if (*str == '\"' && !flag)
			new = strjoin_free(new, convert_dquotes(str + 1, &str), T_DQUOTE);
		else
			new = strjoin_free(new, convert_words(str, &str), T_WORDS);
		if (*str == '\\')
			flag ^= ESC;
		else
			flag = 0;
	}
	ft_free(tokens->word);
	tokens->word = new;
}
