/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 19:35:31 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/23 02:28:09 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	g_sigint;

static int	init(char **buf, char **str)
{
	if (buf)
		if (!(*buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (0);
	if (!(*str))
	{
		if (!(*str = ft_strdup("")))
			return (0);
	}
	else if (g_sigint == ON)
	{
		free(*str);
		if (!(*str = ft_strdup("")))
			return (0);
		g_sigint = OFF;
	}
	return (1);
}

static void	clear(char **p)
{
	free(*p);
	*p = NULL;
}

static int	output(int fd, char **line, int ret, char **str)
{
	char	*tmp;
	int		len;

	if (ret == -1)
	{
		clear(&str[fd]);
		return (-1);
	}
	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (!(*line = ft_substr(str[fd], 0, len)))
		return (-1);
	if (str[fd][len] == '\0')
	{
		clear(&str[fd]);
		return (0);
	}
	len++;
	if (!(tmp = ft_strdup(str[fd] + len)))
		return (-1);
	free(str[fd]);
	str[fd] = tmp;
	return (1);
}

static int	read_file(int fd, char **buf, char **str)
{
	int		ret;
	char	*tmp;

	while ((ret = read(fd, *buf, BUFFER_SIZE)) >= 0)
	{
		init(NULL, str);
		(*buf)[ret] = '\0';
		tmp = ft_strjoin(*str, *buf);
		if (!tmp)
		{
			clear(buf);
			clear(str);
			return (-1);
		}
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

int			get_next_input(int fd, char **line)
{
	int			ret;
	static char	*str[STATIC_MAX];
	char		*buf;

	ret = 1;
	if (BUFFER_SIZE <= 0 || fd < 0 || !line || !(init(&buf, &str[fd])))
		return (-1);
	if (!ft_strchr(str[fd], '\n'))
		ret = read_file(fd, &buf, &str[fd]);
	clear(&buf);
	return (output(fd, line, ret, str));
}
