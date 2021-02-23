/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 02:57:07 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/24 02:58:45 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

static char	*strjoin_free(char *new, char *str)
{
	char	*ret;

	if (!(ret = ft_strjoin(new, str)))
		exit_perror("strjoin_free", EXIT_FAILURE);
	ft_free(str);
	ft_free(new);
	return (ret);
}

void	parse_line(char **line)
{
	int		flag;
	char	*new;
	char	*str;

	flag = 0;
	if (!(new = ft_strdup("")))
		exit_perror("parse_line", EXIT_FAILURE);
	str = *line;
	while (*str)
	{
		if (*str == '\'' && !flag)
			new = strjoin_free(new, convert_quotes(str, &str));
		else if (*str == '\"' && !flag)
			new = strjoin_free(new, convert_dquotes(str, &str));
		else
			new = strjoin_free(new, convert_words(str, &str));
		if (*str == '\\')
			flag ^= ESC;
		else
			flag = 0;
	}
	ft_free(*line);
	*line = new;
}
