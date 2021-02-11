/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_dquotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 02:04:38 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/12 02:22:22 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*convert_dquotes(char *str, char **new)
{
	char	*tmp;
	int		len;

	len = 0;
	while (str[len] != '\"')
		len++;
	str[len] = '\0';
	if (!(tmp = ft_strjoin(*new, str)))
		return (NULL);
	ft_free(*new);
	*new = tmp;
	return (str + len + 1);
}
