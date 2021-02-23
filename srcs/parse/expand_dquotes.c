/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dquotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 02:04:38 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/24 04:03:25 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	is_special_char(char c)
{
	return (c == '$' || c == '`' || c == '\"' || c == '\\' || c == '\n');
}

char		*expand_dquotes(char *new, char **ptr)
{
	char	*tmp;

	tmp = *ptr + 1;
	while (*tmp != '\"')
	{
		if (*tmp == '\\' && is_special_char(*(tmp + 1)))
			tmp++;
		*(new++) = *(tmp++);
	}
	*ptr = tmp + 1;
	return (new);
}
