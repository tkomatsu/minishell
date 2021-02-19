/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 22:24:24 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/19 14:24:11 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	execmd(char **args, int executable)
{
	g_status = EXIT_SUCCESS;
	if (!args[0])
		return (1);
	else if (!ft_strcasecmp(args[0], "echo"))
		return (ft_echo(args));
	else if (!ft_strcasecmp(args[0], "cd"))
		return (ft_cd(args));
	else if (!ft_strcasecmp(args[0], "pwd"))
		return (ft_pwd());
	else if (!ft_strcasecmp(args[0], "export"))
		return (ft_export(args));
	else if (!ft_strcasecmp(args[0], "unset"))
		return (ft_unset(args));
	else if (!ft_strcasecmp(args[0], "env"))
		return (ft_env());
	else if (!ft_strcasecmp(args[0], "exit"))
		return (ft_exit(args));
	else if (is_ultimate_question(args))
		return (STAY_LOOP);
	if (executable)
		return (launch(args));
	return (launch(args));
}
