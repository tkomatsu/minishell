/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_words.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 02:05:04 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/14 16:47:11 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*convert_escape(char *str, char *head, char **new)
{
	char	*tmp;
	char	*ret;
	int		i;
	int		j;

	if (!(tmp = ft_calloc(str - head + 1, sizeof(char))))
		return (NULL);
	i = 0;
	j = 0;
	while (j < str - head)
	{
		if (head[j] == '\\')
			j++;
		tmp[i++] = head[j++];
	}
	if (!(ret = ft_strjoin(*new, tmp)))
		return (NULL);
	ft_free(tmp);
	return (ret);
}

char		*convert_words(char *str, char **new)
{
	char	*tmp;
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
	if (!(tmp = convert_escape(str, head, new)))
		return (NULL);
	ft_free(*new);
	*new = tmp;
	return (str);
}
