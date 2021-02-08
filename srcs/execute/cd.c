/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:05:15 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/08 16:31:24 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_cd(char	**args)
{
	char	*dir;

	if (!args[1] || !ft_strcmp(args[1], "~"))
	{
		if (!(dir = ft_getenv("HOME")))
		{
			ft_putendl_fd("minish: cd: HOME not set", 1);
			return (1);
		}
	}
	else if (!ft_strcmp(args[1], "-"))
	{
		if (!(dir = ft_getenv("OLDPWD")))
		{
			ft_putendl_fd("minish: cd: OLDPWD not set", 1);
			return (1);
		}
	}
	else
		dir = args[1];
	ft_setenv("OLDPWD", ft_getenv("PWD"), 1);
	if (chdir(dir) < 0)
		ft_perror("cd");
	ft_setenv("PWD", getcwd(NULL, 0), 1);
	return (1);
}
