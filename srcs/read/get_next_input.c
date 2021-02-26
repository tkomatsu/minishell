/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 19:35:31 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/26 21:51:02 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

int	g_sigint;

static void	init(char **buf, char **str)
{
	if (buf)
		if (!(*buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			exit_perror("get_next_input", EXIT_FAILURE);
	if (!(*str))
	{
		if (!(*str = ft_strdup("")))
			exit_perror("get_next_input", EXIT_FAILURE);
	}
	else if (g_sigint == ON)
	{
		free(*str);
		if (!(*str = ft_strdup("")))
			exit_perror("get_next_input", EXIT_FAILURE);
		g_sigint = OFF;
	}
}

static int	output(char **line, int ret, char **str)
{
	char	*tmp;
	int		len;

	if (ret == -1)
	{
		clear(str);
		return (-1);
	}
	len = 0;
	while ((*str)[len] != '\n' && (*str)[len] != '\0')
		len++;
	if (!(*line = ft_substr(*str, 0, len)))
		exit_perror("get_next_input", EXIT_FAILURE);
	if ((*str)[len] == '\0')
	{
		clear(str);
		return (0);
	}
	len++;
	if (!(tmp = ft_strdup(*str + len)))
		exit_perror("get_next_input", EXIT_FAILURE);
	free(*str);
	*str = tmp;
	return (1);
}

static int	read_file(char **buf, char **str)
{
	int		ret;
	char	*tmp;

	while ((ret = read(STDIN, *buf, BUFFER_SIZE)) >= 0)
	{
		init(NULL, str);
		(*buf)[ret] = '\0';
		if (!(tmp = ft_strjoin(*str, *buf)))
			exit_perror("get_next_input", EXIT_FAILURE);
		free(*str);
		*str = tmp;
		if (ft_strchr(*str, '\n'))
			break ;
		ft_putstr_fd("  \b\b", STDOUT);
		if (!ret && !**str)
			break ;
	}
	return (ret);
}

int			get_next_input(char **line)
{
	int			ret;
	static char	*str;
	char		*buf;

	ret = 1;
	if (BUFFER_SIZE <= 0 || !line)
		return (-1);
	init(&buf, &str);
	if (!ft_strchr(str, '\n'))
		ret = read_file(&buf, &str);
	clear(&buf);
	return (output(line, ret, &str));
}
