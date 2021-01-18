/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:12:29 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/18 15:43:03 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minish_loop(void)
{
	char	*line;
	char	**cmds;
	char	**args;
	int		status;
	int		i;

	status = 1;
	while (status)
	{
		ft_putstr_fd("> ", 1);
		if (get_next_line(0, &line) < 0)
		{
			perror("get_next_line");
			exit(1);
		}
		cmds = ft_split(line, ';');
		i = 0;
		while (cmds[i])
		{
			args = ft_split(cmds[i], ' ');
			status = execmd(args);
			ft_free_split(args);
			i++;
		}
		ft_free(line);
		ft_free_split(cmds);
	}
}

int		main(void)
{
	ft_putendl_fd("WELCOME TO MINISHELL", 1);
	minish_loop();
	return (EXIT_SUCCESS);
}
