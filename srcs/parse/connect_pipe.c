/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:39:58 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/19 12:10:17 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lstiter_sta(t_list *lst, int (*f)(void *, int))
{
	pid_t	pid;
	int		status;
	int		pipe_fd[2];
	t_list	*head;

	if (!lst || !f)
		return (-1);
	if (pipe(pipe_fd) < 0)
		exit_perror("pipe", 1);
	head = lst;
	while (lst)
	{
		pid = fork();
		if (pid < 0)
			ft_perror("fork");
		else if (!pid) // child
		{
			status = f(lst->content, 1);
			exit(1);
		}
		else // parent
		{
			if (waitpid(pid, &status, WUNTRACED) < 0)
				exit_perror("wait", 1);
		}
		lst = lst->next;
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	return (1);
}
