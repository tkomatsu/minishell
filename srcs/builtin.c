/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:05:15 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/18 15:06:12 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	msh_echo(char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (i > 1)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd(args[i], 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
	return (1);
}

int	msh_cd(char	**args)
{
	if (chdir(args[1]) < 0)
		perror("cd");
	return (1);
}
