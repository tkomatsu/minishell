/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:11:50 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/18 19:31:17 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_env(void)
{
	extern char	**environ;
	int			i;

	i = 0;
	while (environ[i])
		ft_putendl_fd(environ[i++], 1);
	return (1);
}

int	msh_export(char **args)
{
	ft_putenv(args[1]);
	return (1);
}

int	msh_unset(char **args)
{
	printf("\033[31mNeed coding!: unset %s\033[39m\n", args[1]);
	return (1);
}
