/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 02:03:32 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/24 03:47:09 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*expand_quotes(char *new, char **ptr)
{
	char	*tmp;

	tmp = *ptr + 1;
	while (*tmp != '\'')
		*(new++) = *(tmp++);
	*ptr = tmp + 1;
	return (new);
}
