/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_words.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 02:05:04 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/12 02:24:58 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*convert_words(char *str, char **new)
{
	char	*tmp;
	char	*sub;
	int		len;

	len = 0;
	while (!(str[len] == '\'' || str[len] == '\"' || str[len] == '\0'))
		len++;
	if (!(sub = ft_substr(str, 0, len)))
		return (NULL);
	if (!(tmp = ft_strjoin(*new, sub)))
		return (NULL);
	ft_free(*new);
	ft_free(sub);
	*new = tmp;
	return (str + len);
}
