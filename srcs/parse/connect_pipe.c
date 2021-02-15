/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:39:58 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/15 16:46:15 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_pipe(void *content)
{
	char	**args;
	int		status;

	args = convert_lst_to_args((t_token *)content);
	status = execmd(args);
	ft_free(args);
	return (status);
}

int	ft_lstiter_sta(t_list *lst, int (*f)(void *))
{
	pid_t	pid;
	int		status;
	int		pipe_fd[2];
	t_list	*head;

	if (!lst || !f)
		return (-1);
	if (ft_lstsize(lst) > 1)
	{
		if (pipe(pipe_fd) < 0)
		{
			ft_perror("pipe");
			exit(1);
		}
		head = lst;
		while (lst)
		{
			pid = fork();
			if (pid < 0)
				ft_perror("fork");
			else if (!pid) // child
			{
				status = f(lst->content);
				exit(1);
			}
			else // parent
			{
				if (wait(&status) < 0)
				{
					ft_perror("wait");
					exit(1);
				}
			}
			lst = lst->next;
		}
		close(pipe_fd[0]);
		close(pipe_fd[1]);
	}
	else
		status = f(lst->content);
	return (status);
}
