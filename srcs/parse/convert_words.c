/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_words.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 03:12:38 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/24 23:07:59 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static char	*convert_escape(char *new, char *str)
{
	char	*ret;
	char	*tmp;
	int		i;

	ret = NULL;
	tmp = NULL;
	if (!str || !(tmp = ft_strjoin(new, str)))
		exit_perror("convert_escape", EXIT_FAILURE);
	ft_free(new);
	ft_free(str);
	if (!(ret = ft_calloc(ft_strlen(tmp) + 1, sizeof(char))))
		exit_perror("convert_escape", EXIT_FAILURE);
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
	new = convert_escape(new, ft_substr(head, 0, str - head));
	*ptr = str;
	return (new);
}
