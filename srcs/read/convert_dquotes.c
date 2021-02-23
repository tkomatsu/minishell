/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_dquotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 03:00:19 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/24 04:22:38 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

static char	*strjoin_free(char *new, char *str)
{
	char	*ret;

	ret = NULL;
	if (!str || !(ret = ft_strjoin(new, str)))
		exit_perror("convert_dquotes", EXIT_FAILURE);
	ft_free(new);
	ft_free(str);
	return (ret);
}

char		*convert_dquotes(char *str, char **ptr)
{
	char	*new;
	char	*head;
	int		flag;

	new = NULL;
	head = str++;
	flag = 0;
	while (*str != '\"' || (*str == '\"' && (flag & ESC)))
	{
		if (*str == '$' && !(flag & ESC))
		{
			*str = '\0';
			new = expand_environ(str + 1, new, &head, &str);
		}
		if (*(str++) == '\\')
			flag ^= ESC;
		else
			flag = 0;
	}
	new = strjoin_free(new, ft_substr(head, 0, str - head + 1));
	*ptr = str + 1;
	return (new);
}
