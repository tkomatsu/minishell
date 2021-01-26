/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:05:15 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/26 16:40:13 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_cd(char	**args)
{
	ft_setenv("OLDPWD", ft_getenv("PWD"), 1);
	if (!args[1])
	{
		if (chdir(ft_getenv("HOME")) < 0)
			ft_perror("cd");
	}
	else
	{
		if (chdir(args[1]) < 0)
			ft_perror("cd");
	}
	ft_setenv("PWD", getcwd(NULL, 0), 1);
	return (1);
}
