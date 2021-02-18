/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 22:34:03 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/19 03:28:20 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

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
*/

static int	is_bad_quote(char *line)
{
	int	flag;

	flag = 0;
	while (*line)
	{
		if (*line == '\'' && !flag)
			flag ^= QUOTE;
		else if (*line == '"' && !flag)
			flag ^= DQUOTE;
		else if ((*line == '\'' && (flag & QUOTE)) ||
					(*line == '"' && (flag & DQUOTE) && !(flag & ESC)))
			flag = 0;
		if (*line == '\\')
			flag ^= ESC;
		else
			flag &= (QUOTE | DQUOTE);
		line++;
	}
	return (flag & (QUOTE | DQUOTE));
}

int			read_stdin(char **line)
{
	int	ret;

	if ((ret = get_next_input(0, line)) < 0)
	{
		ft_perror("get_next_line");
		exit(1);
	}
	if (!ret)
	{
		ft_putendl_fd("exit", 1);
		exit(0);
	}
	if (is_bad_quote(*line))
	{
		errno = E_QUOTE;
		ft_putstr_fd("minish: ", 2);
		ft_perror(*line);
		return (INVALID_INPUT);
	}
	/*
	while ((ret = is_bad_quote(*line)))
		add_next_line(line, ret);
	*/
	return (VALID_INPUT);
}
