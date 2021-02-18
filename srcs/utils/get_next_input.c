/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 09:58:38 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/19 01:50:05 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	gnl_memerr(char **s1, char **s2, int flag)
{
	free(*s1);
	free(*s2);
	return (flag);
}

static int	gnl_rewrite(char **s1, char **s2)
{
	char	*tmp;

	tmp = ft_strjoin(*s1, *s2);
	free(*s1);
	if (tmp == NULL)
	{
		free(*s2);
		return (-1);
	}
	*s1 = tmp;
	return (0);
}

static int	gnl_return(int fd, char **line, char **buf)
{
	char	*tmp;

	tmp = ft_strchr(buf[fd], '\n');
	if (tmp)
	{
		*tmp = 0;
		if (!(*line = ft_strdup(buf[fd])))
			return (gnl_memerr(line, buf + fd, -1));
		if (!(tmp = ft_strdup(tmp + 1)))
			return (gnl_memerr(line, buf + fd, -1));
		free(buf[fd]);
		buf[fd] = tmp;
		return (1);
	}
	else
	{
		if (!(*line = ft_strdup(buf[fd])))
			return (gnl_memerr(line, buf + fd, -1));
		free(buf[fd]);
		buf[fd] = NULL;
		return (0);
	}
}

static int	is_eof_without_input(int rdno, char *buf)
{
	ft_putstr_fd("  \b\b", 1);
	if (!rdno && !*buf)
		return (1);
	return (0);
}

int			get_next_input(int fd, char **line)
{
	static char *buf[STATIC_MAX];
	char		*rdbuf;
	int			rdno;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(rdbuf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((rdno = read(fd, rdbuf, BUFFER_SIZE)) >= 0)
	{
		rdbuf[rdno] = 0;
		if (gnl_rewrite(&buf[fd], &rdbuf) < 0)
			return (-1);
		if (ft_strchr(buf[fd], '\n'))
		{
			free(rdbuf);
			return (gnl_return(fd, line, buf));
		}
		if (is_eof_without_input(rdno, buf[fd]))
			break ;
	}
	free(rdbuf);
	if (rdno < 0)
		return (-1);
	return (gnl_return(fd, line, buf));
}
