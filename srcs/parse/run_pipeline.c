/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:39:58 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/20 18:19:20 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	run_pipeline(t_list *lst)
{
	pid_t	pid;
	int		newpipe[2];
	int		status;

	while (lst)
	{
		if (lst->next)
			pipe(newpipe);
		pid = fork();
		if (pid < 0)
			ft_perror("fork");
		else if (pid == 0) // child
		{
			if (lst->next)
			{
				close(newpipe[0]);
				dup2(newpipe[1], STDOUT);
				close(newpipe[1]);
			}
			else
			{
				close(newpipe[1]);
				dup2(newpipe[0], STDIN);
				close(newpipe[0]);
			}
			status = run_cmd(lst->content, 1);
			exit(EXIT_SUCCESS);
		}
		else // parent
		{
			if (waitpid(pid, &status, WUNTRACED) < 0)
				exit_perror("wait", 1);
			if (lst->next)
				close(newpipe[1]);
			else
				close(newpipe[0]);
		}
		lst = lst->next;
	}
	return (STAY_LOOP);
}
