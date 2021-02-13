/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 02:03:32 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/13 15:59:53 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*convert_quotes(char *str, char **new)
{
	char	*tmp;
	char	*p_str;

	p_str = str;
	while (*p_str != '\'')
		p_str++;
	*p_str = '\0';
	if (!(tmp = ft_strjoin(*new, str)))
		return (NULL);
	ft_free(*new);
	*new = tmp;
	return (p_str + 1);
}
