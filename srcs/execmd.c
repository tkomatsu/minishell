/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 22:24:24 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/15 21:39:04 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_help(void)
{
	ft_putendl_fd("This is minishell.", 1);
	ft_putendl_fd("Type program names and arguments, and hit enter.", 1);
	return (1);
}

int	msh_exit(void)
{
	return (0);
}

int	msh_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	ft_putendl_fd(path, 1);
	ft_free(path);
	return (1);
}

int	msh_env(void)
{
	extern char	**environ;
	int			i;

	i = 0;
	while (environ[i])
		ft_putendl_fd(environ[i++], 1);
	return (1);
}

int	msh_getenv(char **args)
{
	ft_putendl_fd(ft_getenv(args[1]), 1);
	return 1;
}

int	msh_setenv(char **args)
{
	ft_setenv(args[1], args[2], 1);
	return 1;
}

int	msh_export(char **args)
{
	ft_putenv(args[1]);
	return (1);
}

int	execmd(char **args)
{
	if (!args[0])
		return (1);
	/*
	else if (!ft_strcmp(args[0], "echo"))
		return (msh_echo(args));
	else if (!ft_strcmp(args[0], "cd"))
		return (msh_cd(args));
	*/
	else if (!ft_strcmp(args[0], "pwd"))
		return (msh_pwd());
	else if (!ft_strcmp(args[0], "export"))
		return (msh_export(args));
	/*
	else if (!ft_strcmp(args[0], "unset"))
		return (msh_unset(args));
	*/
	else if (!ft_strcmp(args[0], "env"))
		return (msh_env());
	else if (!ft_strcmp(args[0], "exit"))
		return (msh_exit());
	else if (!ft_strcmp(args[0], "help"))
		return (msh_help());
	else if (!ft_strcmp(args[0], "getenv"))
		return (msh_getenv(args));
	else if (!ft_strcmp(args[0], "setenv"))
		return (msh_setenv(args));
	return (launch(args));
}
