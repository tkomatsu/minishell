/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:35:03 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/01 15:23:09 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		parse_exec(char *line)
{
	char	*cmds;
	char	**args;
	int		status;

	cmds = get_token(line, ";|><");
	while (cmds)
	{
		/* (")を含む分割処理に置き換える */
		args = ft_split(cmds, ' ');

		/* pipe, redirectの処理を追加 */

		/* $などの展開を追加 */

		status = execmd(args);
		ft_free_split(args);
		cmds = get_token(NULL, ";|><");
	}
	return (status);
}
