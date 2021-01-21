/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 22:34:03 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/21 23:17:16 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_is_bad_quote(char *line)
{
	int	flag;

	flag = 0;
	if (*line == ''')
		flag = QUOTE;
	else if (*line == '"')
		flag = DQUOTE;
	line++;
	while (*line)
	{
		if (!flag && *line == ''' && *(line - 1) != '\')
			flag == QUOTE;
		else if (!flag && *line == '"' && *(line - 1) != '\')
			flag == DQUOTE;
		else if ((flag == QUOTE && *line == ''') ||
					(flag == DQUOTE && *line == '"'))
			flag = 0;
		line++;
	}
	return (flag);
}

int	read_arg(char **line)
{
	int	ret;

	if ((ret = get_next_line(0, line)) < 0)
	{
		perror("get_next_line");
		exit(1);
	}
	return (0);
}
