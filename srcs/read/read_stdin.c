/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 22:34:03 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/26 21:45:10 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

static int	output_eof_err(int flag)
{
	if (flag == QUOTE)
		ft_putendl_fd("minish: unexpected EOF while looking for matching `\''"
				, STDERR);
	else if (flag == DQUOTE)
		ft_putendl_fd("minish: unexpected EOF while looking for matching `\"'"
				, STDERR);
	errno = E_EOF;
	ft_perror("minish: syntax error");
	g_status = EX_EINPUT;
	return (INVALID_INPUT);
}

static int	add_next_line(char **line, int flag)
{
	int	ret;
	int	is_sigint;

	is_sigint = OFF;
	if (flag == QUOTE || flag == DQUOTE)
		put_prompt("PS2");
	if ((ret = add_next_input(line, &is_sigint)) < 0)
		exit_perror("add_next_input", EXIT_FAILURE);
	if (!ret && is_sigint == OFF)
		return (output_eof_err(flag));
	else if (!ret && is_sigint == ON)
	{
		ft_putendl_fd("exit", STDOUT);
		exit(EXIT_SUCCESS);
	}
	return (VALID_INPUT);
}

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

	if ((ret = get_next_input(line)) < 0)
		exit_perror("get_next_input", EXIT_FAILURE);
	if (!ret)
	{
		ft_putendl_fd("exit", STDOUT);
		exit(EXIT_SUCCESS);
	}
	while ((ret = is_bad_quote(*line)))
		if (add_next_line(line, ret) == INVALID_INPUT)
			return (INVALID_INPUT);
	return (VALID_INPUT);
}
