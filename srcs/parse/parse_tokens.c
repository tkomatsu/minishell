/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:17:47 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/18 15:221:36 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void		parse_tokens(void *content)
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
			new = strjoin_free(new, convert_quotes(str + 1, &str), QUOTE);
		else if (*str == '\"' && !flag)
			new = strjoin_free(new, convert_dquotes(str + 1, &str), DQUOTE);
		else
			new = strjoin_free(new, convert_words(str, &str), 0);
		if (*str == '\\')
			flag ^= ESC;
		else
			flag = 0;
	}
	ft_free(tokens->word);
	tokens->word = new;
}
