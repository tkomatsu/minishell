/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 02:03:32 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/18 21:00:29 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*convert_quotes(char *str, char **ptr)
{
	char	*new;

	new = str;
	while (*str != '\'')
		str++;
	*str = '\0';
	*ptr = str + 1;
	return (new);
}
