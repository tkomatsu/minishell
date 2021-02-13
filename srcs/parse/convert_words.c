/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_words.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 02:05:04 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/13 15:51:27 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*convert_words(char *str, char **new)
{
	char	*tmp;
	char	*sub;
	int		flag;
	char	*p_str;

	flag = 0;
	p_str = str;
	while (!(*p_str == '\'' || *p_str == '\"' || *p_str == '\0')
			|| ((*p_str == '\'' || *p_str == '\"') && (flag & ESC)))
	{
		if (*p_str == '$' && !(flag & ESC))
		{
			*p_str = '\0';
			if (!(p_str = parse_var(p_str + 1, &str, new)))
				return (NULL);
		}
		if (*(p_str++) == '\\')
			flag ^= ESC;
		else
			flag = 0;
	}
	if (!(sub = ft_substr(str, 0, p_str - str)))
		return (NULL);
	if (!(tmp = ft_strjoin(*new, sub)))
		return (NULL);
	ft_free(sub);
	ft_free(*new);
	*new = tmp;
	return (p_str);
}
