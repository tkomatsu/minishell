/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_words.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 03:12:38 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/24 14:55:59 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

static void	validate_escape(char c, int *flag)
{
	if (c == '\\')
		*flag ^= ESC;
	else
		*flag = 0;
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
			if (*(str + 1) == '\"' || *(str + 1) == '\'')
			{
				str++;
				break ;
			}
			new = expand_environ(str + 1, new, &head, &str);
		}
		validate_escape(*(str++), &flag);
	}
	new = strjoin_free(new, ft_substr(head, 0, str - head));
	*ptr = str;
	return (new);
}
