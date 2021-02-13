/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 22:24:24 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/13 19:48:23 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execmd(char **args)
{
	g_status = EXIT_SUCCESS;
	if (!args[0])
		return (1);
	else if (!ft_strcmp(args[0], "echo"))
		return (msh_echo(args));
	else if (!ft_strcmp(args[0], "cd"))
		return (msh_cd(args));
	else if (!ft_strcmp(args[0], "pwd"))
		return (msh_pwd());
	else if (!ft_strcmp(args[0], "export"))
		return (msh_export(args));
	else if (!ft_strcmp(args[0], "unset"))
		return (msh_unset(args));
	else if (!ft_strcmp(args[0], "env"))
		return (msh_env());
	else if (!ft_strcmp(args[0], "exit"))
		return (msh_exit());
	else if (is_ultimate_question(args))
		return (1);
	return (launch(args));
}
