/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 02:57:07 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/24 14:55:30 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

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
