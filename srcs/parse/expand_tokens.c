/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:17:47 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/24 04:31:23 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	expand_token(t_token *tokens)
{
	char	*new;
	char	*head;
	char	*str;
	int		flag;

	flag = 0;
	if (!(new = ft_calloc(ft_strlen(tokens->word) + 1, sizeof(char))))
		exit_perror("expand_word", EXIT_FAILURE);
	head = new;
	str = tokens->word;
	while (*str)
	{
		if (*str == '\'' && !flag)
			new = expand_quotes(new, &str);
		else if (*str == '\"' && !flag)
			new = expand_dquotes(new, &str);
		else
			new = expand_words(new, &str);
		if (*str == '\\')
			flag ^= ESC;
		else
			flag = 0;
	}
	ft_free(tokens->word);
	tokens->word = head;
}

void		expand_tokens(void *content)
{
	t_token *tokens;

	tokens = (t_token*)content;
	while (tokens)
	{
		expand_token(tokens);
		tokens = tokens->next;
	}
}
