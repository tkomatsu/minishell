/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 22:24:24 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/18 19:31:39 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execmd(char **args)
{
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
	return (launch(args));
}
