/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:12:29 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/11 12:58:12 by tkomatsu         ###   ########.fr       */
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
		free(line);
		free(args);	// splitのメモリ解放は要確認
	}
}

int		main(void)
{
	ft_putendl_fd("Welcome to minishell :)", 1);
	minish_loop();
	return (EXIT_SUCCESS);
}
