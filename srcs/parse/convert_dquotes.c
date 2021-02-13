/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_dquotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 02:04:38 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/13 15:31:06 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*convert_dquotes(char *str, char **new)
{
	char	*tmp;
	int		flag;
	char	*p_str;

	flag = 0;
	p_str = str;
	while (*p_str != '\"' || (*p_str == '\"' && (flag & ESC)))
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
	*p_str = '\0';
	if (!(tmp = ft_strjoin(*new, str)))
		return (NULL);
	ft_free(*new);
	*new = tmp;
	return (p_str + 1);
}
