/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:09:35 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/03/07 10:21:12 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int			run_cmd(void *content)
{
	char	**args;
	int		status;
	int		original_fd[3];

	original_fd[0] = dup(STDIN);
	original_fd[1] = dup(STDOUT);
	original_fd[2] = dup(STDERR);
	status = set_redirect((t_token *)content);
	args = token_to_args((t_token *)content);
	if (!status)
		status = execmd(argslen(args), args);
	free(args);
	dup2(original_fd[0], STDIN);
	close(original_fd[0]);
	dup2(original_fd[1], STDOUT);
	close(original_fd[1]);
	dup2(original_fd[2], STDERR);
	close(original_fd[2]);
	return (status);
}
