/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 23:16:39 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/22 11:45:22 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	io_redirect(t_token *token)
{
	int		file_fd;
	int		wish_fd;
	char	*path;

	file_fd = -1;
	wish_fd = ft_atoi(token->word);
	if (wish_fd <= 0)
	{
		if (token->type == GREATER || token->type == GREATER2)
			wish_fd = STDOUT;
		else if (token->type == LESS)
			wish_fd = STDIN;
	}
	else
	{
		ft_free(token->word);
		token->word = ft_strdup("");
	}
	if (!token->next)
	{
		ft_perror("redirect syntax error");
		return ;
	}
	path = ft_strdup(token->next->word);
	dlstextract(token->next);
	if (token->type == GREATER)
		file_fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	else if (token->type == LESS)
		file_fd = open(path, O_RDONLY);
	if (file_fd < 0)
		exit_perror("error", EXIT_FAILURE);
	ft_free(path);
	dup2(file_fd, wish_fd);
	close(file_fd);
}

void		set_redirect(t_token *token)
{
	while (token)
	{
		if (token->type == LESS || token->type == GREATER ||
			token->type == GREATER2)
			io_redirect(token);
		token = token->next;
	}
}
