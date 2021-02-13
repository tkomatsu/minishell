/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_dquotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 02:04:38 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/12 21:18:28 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*convert_dquotes(char *str, char **new)
{
	char	*tmp;
	int		flag;
	int		len;

	flag = 0;
	len = 0;
	while (str[len] != '\"' || (str[len] == '\"' && (flag & ESC)))
	{
		if (str[len] == '\\')
			flag ^= ESC;
		else
			flag = 0;
		len++;
	}
	str[len] = '\0';
	if (!(tmp = ft_strjoin(*new, str)))
		return (NULL);
	ft_free(*new);
	*new = tmp;
	return (str + len + 1);
}
