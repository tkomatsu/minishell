/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 19:16:51 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/03/01 19:19:42 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	strtofd(t_token *token)
{
	int	fd;

	fd = ft_atoi(token->word);
	if (fd <= 0)
	{
		if (token->type == GREATER || token->type == GREATER2)
			fd = STDOUT;
		else if (token->type == LESS)
			fd = STDIN;
	}
	else
	{
		free(token->word);
		token->word = ft_strdup("");
	}
	return (fd);
}

static int	open_redirect(t_token *token, char *path)
{
	int	file_fd;

	file_fd = -1;
	if (token->type == GREATER)
		file_fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	else if (token->type == GREATER2)
		file_fd = open(path, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	else if (token->type == LESS)
		file_fd = open(path, O_RDONLY);
	return (file_fd);
}

static int	exit_failure(char *path)
{
	g_status = EXIT_FAILURE;
	ft_putstr_fd("minish: ", STDERR);
	ft_perror(path);
	return (EXIT_FAILURE);
}

static int	dup_failure(int fd)
{
	char	*path;

	g_status = EXIT_FAILURE;
	ft_putstr_fd(path = ft_itoa(fd), STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putendl_fd(strerror(EBADF), STDERR);
	free(path);
	return (EXIT_FAILURE);
}

int			io_redirect(t_token *token)
{
	int		file_fd;
	int		wish_fd;
	char	*path;

	wish_fd = strtofd(token);
	if (!token->next || !*(token->next->word))
	{
		g_status = EXIT_FAILURE;
		ft_putendl_fd("minish: syntax error near unexpected token `newline'",
						STDERR);
		return (EXIT_FAILURE);
	}
	path = ft_strdup(token->next->word);
	dlstextract(token->next);
	file_fd = open_redirect(token, path);
	if (file_fd < 0)
		return (exit_failure(path));
	free(path);
	if (dup2(file_fd, wish_fd) < 0)
		return (dup_failure(wish_fd));
	close(file_fd);
	return (EXIT_SUCCESS);
}
