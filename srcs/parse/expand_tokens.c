/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:17:47 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/04 01:29:31 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	remove_word(t_token *token)
{
	free(token->word);
	token->word = NULL;
}

static char	*strjoin_free(char *new, char *str, int type)
{
	char	*ret;

	if (!(ret = ft_strjoin(new, str)))
		exit_perror("strjoin_free", EXIT_FAILURE);
	if (type != QUOTE)
		free(str);
	free(new);
	return (ret);
}

static void	expand_token(t_token *tokens)
{
	int		flag;
	char	*new;
	char	*str;

	flag = 0;
	if (!(new = ft_strdup("")))
		exit_perror("expand_token", EXIT_FAILURE);
	str = tokens->word;
	while (*str)
	{
		if (*str == '\'' && !flag)
			new = strjoin_free(new, convert_quotes(str + 1, &str), T_QUOTE);
		else if (*str == '\"' && !flag)
			new = strjoin_free(new, convert_dquotes(str + 1, &str), T_DQUOTE);
		else
		{
			new = strjoin_free(new, convert_words(str, &str, tokens), T_WORDS);
			if (!*new)
				return (remove_word(tokens));
		}
		validate_escape(*str, &flag);
	}
	free(tokens->word);
	tokens->word = new;
}

void		expand_tokens(void *content)
{
	t_token *tokens;

	tokens = (t_token*)content;
	while (tokens)
	{
		if (!*tokens->word)
			remove_word(tokens);
		else
			expand_token(tokens);
		tokens = tokens->next;
	}
}
