/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_words.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 02:05:04 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/18 21:00:40 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static char	*convert_escape(char *new, char *str)
{
	char	*ret;
	char	*tmp;
	int		i;

	if (!str || !(tmp = ft_strjoin(new, str)))
		return (NULL);
	ft_free(new);
	ft_free(str);
	if (!(ret = ft_calloc(ft_strlen(tmp) + 1, sizeof(char))))
		return (NULL);
	i = 0;
	new = tmp;
	while (*tmp)
	{
		if (*tmp == '\\')
			tmp++;
		ret[i++] = *(tmp++);
	}
	ft_free(new);
	return (ret);
}

char		*convert_words(char *str, char **ptr)
{
	char	*new;
	char	*head;
	int		flag;

	new = NULL;
	head = str;
	flag = 0;
	while (!(*str == '\'' || *str == '\"' || *str == '\0')
			|| ((*str == '\'' || *str == '\"') && (flag & ESC)))
	{
		if (*str == '$' && !(flag & ESC))
		{
			*str = '\0';
			if (!(new = parse_var(str + 1, new, &head, &str)))
				return (NULL);
		}
		if (*(str++) == '\\')
			flag ^= ESC;
		else
			flag = 0;
	}
	if (!(new = convert_escape(new, ft_substr(head, 0, str - head))))
		return (NULL);
	*ptr = str;
	return (new);
}
