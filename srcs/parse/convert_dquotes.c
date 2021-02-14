/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_dquotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 02:04:38 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/14 15:15:33 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*convert_dquotes(char *str, char **new)
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
	if (!(tmp = ft_strjoin(*new, head)))
		return (NULL);
	ft_free(*new);
	*new = tmp;
	return (str + 1);
}
