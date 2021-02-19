/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:09:35 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/19 12:10:00 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	run_cmd(void *content, int flag)
{
	char	**args;
	int		status;

	args = token_to_args((t_token *)content);
	status = execmd(args, flag);
	ft_free(args);
	return (status);
}
