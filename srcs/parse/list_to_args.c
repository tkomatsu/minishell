/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:36:17 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/18 21:01:32 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char		**convert_lst_to_args(t_token *tokens)
{
	char	**args;
	int		i;

	/* redirect */
	if (!(args = ft_calloc(token_size(tokens) + 1, sizeof(char*))))
		return (NULL);
	i = 0;
	while (tokens)
	{
		if (!(tokens->word = parse_tokens(tokens)))
			return (NULL);
		if (*(tokens->word))
			args[i++] = tokens->word;
		tokens = tokens->next;
	}
	return (args);
}
