/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_words.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 02:05:04 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/14 15:18:16 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*convert_words(char *str, char **new)
{
	char	*tmp;
	char	*sub;
	char	*head;
	int		flag;

	flag = 0;
	head = str;
	while (!(*str == '\'' || *str == '\"' || *str == '\0')
			|| ((*str == '\'' || *str == '\"') && (flag & ESC)))
	{
		if (*str == '$' && !(flag & ESC))
		{
			*str = '\0';
			if (!(str = parse_var(str + 1, &head, new)))
				return (NULL);
		}
		if (*(str++) == '\\')
			flag ^= ESC;
		else
			flag = 0;
	}
	if (!(sub = ft_substr(head, 0, str - head)))
		return (NULL);
	if (!(tmp = ft_strjoin(*new, sub)))
		return (NULL);
	ft_free(sub);
	ft_free(*new);
	*new = tmp;
	return (str);
}
