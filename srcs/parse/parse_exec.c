/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:35:03 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/01 09:52:20 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		parse_exec(char *line)
{
	char	*cmds;
	char	**args;
	int		status;

	cmds = ft_strtok(line, ";|><");
	while (cmds)
	{
		args = ft_split(cmds, ' ');
		status = execmd(args);
		ft_free_split(args);
		cmds = ft_strtok(NULL, ";|><");
	}
	return (status);
}
