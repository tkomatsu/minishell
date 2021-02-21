/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:09:35 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/21 13:51:24 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	run_cmd(void *content, int flag)
{
	char	**args;
	int		status;

	set_redirect((t_token*)content);
	args = token_to_args((t_token *)content);
	status = execmd(args, flag);
	ft_free(args);
	return (status);
}
