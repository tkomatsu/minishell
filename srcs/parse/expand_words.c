/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 02:05:04 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/24 04:03:58 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char		*expand_words(char *new, char **ptr)
{
	char	*tmp;

	tmp = *ptr;
	while (!(*tmp == '\'' || *tmp == '\"' || *tmp == '\0'))
	{
		if (*tmp == '\\')
			tmp++;
		*(new++) = *(tmp++);
	}
	*ptr = tmp;
	return (new);
}
