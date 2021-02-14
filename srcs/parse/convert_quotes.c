/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 02:03:32 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/14 15:16:33 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*convert_quotes(char *str, char **new)
{
	char	*tmp;
	char	*head;

	head = str;
	while (*str != '\'')
		str++;
	*str = '\0';
	if (!(tmp = ft_strjoin(*new, head)))
		return (NULL);
	ft_free(*new);
	*new = tmp;
	return (str + 1);
}
