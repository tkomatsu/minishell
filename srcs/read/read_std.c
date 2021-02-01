/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_std.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 22:34:03 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/01 09:39:08 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
static void	add_next_line(char **line, int flag)
{
	int		ret;
	char	*new;
	char	*put_nl;
	char	*tmp;

	if (flag == QUOTE)
		ft_putstr_fd("quote> ", 1);
	else if (flag == DQUOTE)
		ft_putstr_fd("dquote> ", 1);
	if ((ret = get_next_line(0, &tmp)) < 0)
	{
		ft_perror("get_next_line");
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
*/

int			read_std(char **line)
{
	int	ret;

	if ((ret = get_next_line(0, line)) < 0)
	{
		ft_perror("get_next_line");
		exit(1);
	}
	/*
	while ((ret = is_bad_quote(*line)))
		add_next_line(line, ret);
	*/
	return (0);
}
