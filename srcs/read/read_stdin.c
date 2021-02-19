/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 22:34:03 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/19 23:47:04 by kefujiwa         ###   ########.fr       */
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
		ft_putstr_fd("quote> ", STDOUT);
	else if (flag == DQUOTE)
		ft_putstr_fd("dquote> ", STDOUT);
	if ((ret = get_next_line(0, &tmp)) < 0)
	{
		ft_perror("get_next_line");
		exit(EXIT_FAILURE);
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
		exit_perror("get_next_input", EXIT_FAILURE);
	if (!ret)
	{
		ft_putendl_fd("exit", STDOUT);
		exit(EXIT_SUCCESS);
	}
	if (is_bad_quote(*line))
	{
		errno = E_QUOTE;
		ft_putstr_fd("minish: ", STDERR);
		ft_perror(*line);
		return (INVALID_INPUT);
	}
	/*
	while ((ret = is_bad_quote(*line)))
		add_next_line(line, ret);
	*/
	return (VALID_INPUT);
}
