/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 23:16:39 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/22 16:58:12 by tkomatsu         ###   ########.fr       */
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
		ft_free(token->word);
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

static int	io_redirect(t_token *token)
{
	int		file_fd;
	int		wish_fd;
	char	*path;

	wish_fd = strtofd(token);
	if (!token->next)
	{
		ft_putendl_fd("minish: syntax error", STDERR);
		return (EXIT_FAILURE);
	}
	path = ft_strdup(token->next->word);
	dlstextract(token->next);
	file_fd = open_redirect(token, path);
	if (file_fd < 0)
	{
		ft_putstr_fd("minish: ", STDERR);
		ft_perror(path);
		return (EXIT_FAILURE);
	}
	ft_free(path);
	dup2(file_fd, wish_fd);
	close(file_fd);
	return (EXIT_SUCCESS);
}

int			set_redirect(t_token *token)
{
	int	status;

	status = 0;
	while (token)
	{
		if (token->type == LESS || token->type == GREATER ||
			token->type == GREATER2)
			if ((status = io_redirect(token)) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		token = token->next;
	}
	return (EXIT_SUCCESS);
}
