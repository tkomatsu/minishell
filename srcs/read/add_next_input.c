/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_next_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 21:40:39 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/26 21:47:18 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

static void	sigint_process(char **str, char **line, int *is_sigint)
{
	clear(line);
	free(*str);
	if (!(*str = ft_strdup("")))
		exit_perror("add_next_input", EXIT_FAILURE);
	if (is_sigint)
		*is_sigint = ON;
	g_sigint = OFF;
}

static void	init(char **buf, char **str, char **line, int *is_sigint)
{
	char	*tmp;

	if (line)
	{
		tmp = *line;
		*line = ft_strjoin(tmp, "\n");
		free(tmp);
	}
	if (buf)
		if (!(*buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			exit_perror("add_next_input", EXIT_FAILURE);
	if (!(*str))
	{
		if (!(*str = ft_strdup("")))
			exit_perror("add_next_input", EXIT_FAILURE);
	}
	else if (g_sigint == ON)
		sigint_process(str, line, is_sigint);
}

static int	output(char **line, char **str)
{
	char	*tmp;
	char	*src;
	int		len;

	len = 0;
	while ((*str)[len] != '\n' && (*str)[len] != '\0')
		len++;
	src = *line;
	if (!(tmp = ft_substr(*str, 0, len)))
		exit_perror("add_next_input", EXIT_FAILURE);
	if (!(*line = ft_strjoin(src, tmp)))
		exit_perror("add_next_input", EXIT_FAILURE);
	free(src);
	free(tmp);
	if ((*str)[len] == '\0')
	{
		clear(str);
		return (0);
	}
	len++;
	if (!(tmp = ft_strdup(*str + len)))
		exit_perror("add_next_input", EXIT_FAILURE);
	free(*str);
	*str = tmp;
	return (1);
}

static int	read_file(char **buf, char **str, char **line, int *is_sigint)
{
	int		ret;
	char	*tmp;

	while ((ret = read(STDIN, *buf, BUFFER_SIZE)) >= 0)
	{
		init(NULL, str, line, is_sigint);
		(*buf)[ret] = '\0';
		if (!(tmp = ft_strjoin(*str, *buf)))
			exit_perror("add_next_input", EXIT_FAILURE);
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

int			add_next_input(char **line, int *is_sigint)
{
	int			ret;
	static char	*str;
	char		*buf;

	ret = 1;
	if (BUFFER_SIZE <= 0 || !line)
		return (-1);
	init(&buf, &str, NULL, NULL);
	if (!ft_strchr(str, '\n'))
		ret = read_file(&buf, &str, line, is_sigint);
	clear(&buf);
	if (ret == -1)
	{
		clear(&str);
		return (-1);
	}
	return (output(line, &str));
}
