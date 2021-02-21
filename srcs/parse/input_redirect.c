/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 13:15:31 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/21 21:04:22 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	input_redirect(t_token *token)
{
	int		file_fd;
	char	*path;

	if (!token->next)
	{
		ft_perror("redirect syntax error");
		return ;
	}
	path = ft_strdup(token->next->word);
	dlstextract(token->next);
	file_fd = open(path, O_RDONLY);
	ft_free(path);
	dup2(file_fd, STDIN);
	close(file_fd);
}
