/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:36:17 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/03/01 18:29:04 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char		**token_to_args(t_token *tokens)
{
	char	**args;
	int		i;

	if (!(args = ft_calloc(token_size(tokens) + 1, sizeof(char*))))
		exit_perror("token_to_args", EXIT_FAILURE);
	i = 0;
	while (tokens)
	{
		if (tokens->type == WORD)
			args[i++] = tokens->word;
		tokens = tokens->next;
	}
	return (args);
}
