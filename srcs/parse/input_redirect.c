/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 13:15:31 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/21 13:50:57 by tkomatsu         ###   ########.fr       */
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
	file_fd = open(path, O_RDONLY);
	dup2(file_fd, STDIN);
	close(file_fd);
}
