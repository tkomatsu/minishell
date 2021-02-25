/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:39:58 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/25 18:34:42 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	child_proc(t_list *head, t_list *cur, int oldp[2], int newp[2])
{
	if (cur != head)
	{
		close(oldp[1]);
		dup2(oldp[0], STDIN);
		close(oldp[0]);
	}
	if (cur->next)
	{
		close(newp[0]);
		dup2(newp[1], STDOUT);
		close(newp[1]);
	}
	run_cmd(cur->content, 1);
	ft_lstclear(&head, clear_tokens);
	ft_free_split(g_env);
	exit(g_status);
}

static void	parent_proc(t_list *head, t_list *cur, int oldp[2])
{
	int	status;

	if (cur != head)
	{
		close(oldp[0]);
		close(oldp[1]);
	}
	if (waitpid(g_pid, &status, WUNTRACED) < 0)
		exit_perror("wait", EXIT_FAILURE);
	if (status == SIGINT || status == SIGQUIT)
		signal_handler(status);
	if (WIFEXITED(status))
		g_status = WEXITSTATUS(status);
}

static void	exec_pipeline(t_list *lst)
{
	int		lastpipe[2];
	int		newpipe[2];
	t_list	*head;

	head = lst;
	while (lst)
	{
		lastpipe[0] = newpipe[0];
		lastpipe[1] = newpipe[1];
		if (lst->next)
			if (pipe(newpipe) < 0)
				exit_perror("pipe", EXIT_FAILURE);
		g_pid = fork();
		if (g_pid < 0)
			exit_perror("fork", EXIT_FAILURE);
		else if (g_pid == 0)
			child_proc(head, lst, lastpipe, newpipe);
		else
			parent_proc(head, lst, lastpipe);
		lst = lst->next;
	}
}

int			run_pipeline(t_list *lst)
{
	int	original_stdin;
	int	original_stdout;

	signal(SIGINT, signal_ignore);
	signal(SIGQUIT, signal_ignore);
	original_stdin = dup(STDIN);
	original_stdout = dup(STDOUT);
	exec_pipeline(lst);
	dup2(original_stdin, STDIN);
	close(original_stdin);
	dup2(original_stdout, STDOUT);
	close(original_stdout);
	return (STAY_LOOP);
}
