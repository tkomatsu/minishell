/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:12:29 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/12 22:58:07 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minish_loop(void)
{
	char	*line;
	char	**args;
	int		status;

	status = 1;
	while (status)
	{
		ft_putstr_fd("> ", 1);
		if (get_next_line(0, &line) < 0)
		{
			perror("get_next_line");
			exit(1);
		}
		args = ft_split(line, ' ');
		status = execmd(args);
		ft_free(line);
		ft_free_split(args);
	}
}

int		main(void)
{
	ft_putendl_fd("WELCOME TO MINISHELL", 1);
	minish_loop();
	return (EXIT_SUCCESS);
}
