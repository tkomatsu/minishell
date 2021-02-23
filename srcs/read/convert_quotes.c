/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 02:59:14 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/24 04:22:30 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

char	*convert_quotes(char *str, char **ptr)
{
	char	*new;
	char	*head;

	head = str++;
	while (*str != '\'')
		str++;
	new = ft_substr(head, 0, str - head + 1);
	*ptr = str + 1;
	return (new);
}
