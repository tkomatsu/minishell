/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:35:03 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/26 11:57:24 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		parse_exec(char *line)
{
	char	**cmds;
	char	**args;
	int		i;
	int		status;

	cmds = ft_split(line, ';');
	i = 0;
	while (cmds[i])
	{
		args = ft_split(cmds[i], ' ');
		status = execmd(args);
		ft_free_split(args);
		i++;
	}
	ft_free_split(cmds);
	return (status);
}
