/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 22:34:03 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/22 01:41:49 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_next_line(char **line)
{
	int		ret;
	char	*new;
	char	*put_nl;
	char	*tmp;

	ft_putstr_fd("> ", 1);
	if ((ret = get_next_line(0, &tmp)) < 0)
	{
		perror("get_next_line");
		exit(1);
	}
	put_nl = ft_strjoin("\n", tmp);
	free(tmp);
	new = ft_strjoin(*line, put_nl);
	free(put_nl);
	free(*line);
	*line = new;
}

static int	is_bad_quote(char *line)
{
	int	flag;

	flag = 0;
	if (*line == '\'')
		flag = QUOTE;
	else if (*line == '\"')
		flag = DQUOTE;
	line++;
	while (*line)
	{
		if (!flag && *line == '\'' && *(line - 1) != '\\')
			flag = QUOTE;
		else if (!flag && *line == '\"' && *(line - 1) != '\\')
			flag = DQUOTE;
		else if ((flag == QUOTE && *line == '\'') ||
					(flag == DQUOTE && *line == '\"'))
			flag = 0;
		line++;
	}
	return (flag);
}

int			read_arg(char **line)
{
	int	ret;

	if ((ret = get_next_line(0, line)) < 0)
	{
		perror("get_next_line");
		exit(1);
	}
	while (is_bad_quote(*line))
		add_next_line(line);
	return (0);
}
