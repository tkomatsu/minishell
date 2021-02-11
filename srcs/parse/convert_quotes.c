/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 02:03:32 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/12 02:24:14 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*convert_quotes(char *str, char **new)
{
	char	*tmp;
	int		len;

	len = 0;
	while (str[len] != '\'')
		len++;
	str[len] = '\0';
	if (!(tmp = ft_strjoin(*new, str)))
		return (NULL);
	ft_free(*new);
	*new = tmp;
	return (str + len + 1);
}
