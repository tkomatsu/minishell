/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_dquotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 02:04:38 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/19 20:50:19 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	is_special_char(char c)
{
	return (c == '$' || c == '`' || c == '\"' || c == '\\' || c == '\n');
}

static char	*convert_escape(char *new, char *head)
{
	char	*ret;
	char	*tmp;
	int		i;

	if (!(tmp = ft_strjoin(new, head)))
		return (NULL);
	ft_free(new);
	if (!(ret = ft_calloc(ft_strlen(tmp) + 1, sizeof(char))))
		return (NULL);
	i = 0;
	new = tmp;
	while (*tmp)
	{
		if (*tmp == '\\' && is_special_char(*(tmp + 1)))
			tmp++;
		ret[i++] = *(tmp++);
	}
	ft_free(new);
	return (ret);
}

char		*convert_dquotes(char *str, char **ptr)
{
	char	*new;
	char	*head;
	int		flag;

	new = NULL;
	head = str;
	flag = 0;
	while (*str != '\"' || (*str == '\"' && (flag & ESC)))
	{
		if (*str == '$' && !(flag & ESC))
		{
			*str = '\0';
			if (!(new = expand_environ(str + 1, new, &head, &str)))
				return (NULL);
		}
		if (*(str++) == '\\')
			flag ^= ESC;
		else
			flag = 0;
	}
	*str = '\0';
	if (!(new = convert_escape(new, head)))
		return (NULL);
	*ptr = str + 1;
	return (new);
}
