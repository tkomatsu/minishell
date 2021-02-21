/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:06:20 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/21 21:33:48 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	output_redirect(t_token *token)
{
	int	file_fd;
	int	wish_fd;
	char *path;

	wish_fd = ft_atoi(token->word);
	if (wish_fd <= 0)
		wish_fd = STDOUT;
	if (!token->next)
	{
		ft_perror("redirect syntax error");
		return ;
	}
	path = ft_strdup(token->next->word);
	dlstextract(token->next);
	file_fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	ft_free(path);
	dup2(file_fd, wish_fd);
	close(file_fd);
}
