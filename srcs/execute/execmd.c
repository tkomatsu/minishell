/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 22:24:24 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/19 12:12:56 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execmd(char **args, int executable)
{
	g_status = EXIT_SUCCESS;
	if (!args[0])
		return (1);
	else if (!ft_strcasecmp(args[0], "echo"))
		return (msh_echo(args));
	else if (!ft_strcasecmp(args[0], "cd"))
		return (msh_cd(args));
	else if (!ft_strcasecmp(args[0], "pwd"))
		return (msh_pwd());
	else if (!ft_strcasecmp(args[0], "export"))
		return (msh_export(args));
	else if (!ft_strcasecmp(args[0], "unset"))
		return (msh_unset(args));
	else if (!ft_strcasecmp(args[0], "env"))
		return (msh_env());
	else if (!ft_strcasecmp(args[0], "exit"))
		return (msh_exit(args));
	else if (is_ultimate_question(args))
		return (1);
	if (executable)
		return (launch(args));
	return (-1);
}
