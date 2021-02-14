/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_dquotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 02:04:38 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/14 18:17:11 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_special_char(char c)
{
	return (c == '$' || c == '`' || c == '\"' || c == '\\' || c == '\n');
}

static char	*convert_escape(char *head, char **new)
{
	char	*tmp;
	char	*ret;
	int		i;

	if (!(tmp = ft_calloc(ft_strlen(head) + 1, sizeof(char))))
		return (NULL);
	i = 0;
	while (*head)
	{
		if (*head == '\\' && is_special_char(*(head + 1)))
			head++;
		tmp[i++] = *(head++);
	}
	if (!(ret = ft_strjoin(*new, tmp)))
		return (NULL);
	ft_free(tmp);
	return (ret);
}

char		*convert_dquotes(char *str, char **new)
{
	char	*tmp;
	char	*head;
	int		flag;

	flag = 0;
	head = str;
	while (*str != '\"' || (*str == '\"' && (flag & ESC)))
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
	*str = '\0';
	if (!(tmp = convert_escape(head, new)))
		return (NULL);
	ft_free(*new);
	*new = tmp;
	return (str + 1);
}
