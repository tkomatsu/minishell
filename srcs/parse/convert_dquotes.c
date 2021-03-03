/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_dquotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 03:00:19 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/04 01:14:52 by kefujiwa         ###   ########.fr       */
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
		exit_perror("convert_escape", EXIT_FAILURE);
	free(new);
	if (!(ret = ft_calloc(ft_strlen(tmp) + 1, sizeof(char))))
		exit_perror("convert_escape", EXIT_FAILURE);
	i = 0;
	new = tmp;
	while (*tmp)
	{
		if (*tmp == '\\' && is_special_char(*(tmp + 1)))
			tmp++;
		ret[i++] = *(tmp++);
	}
	free(new);
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
			new = expand_environ(str + 1, new, &head, &str);
		}
		validate_escape(*(str++), &flag);
	}
	*str = '\0';
	new = convert_escape(new, head);
	*ptr = str + 1;
	return (new);
}
