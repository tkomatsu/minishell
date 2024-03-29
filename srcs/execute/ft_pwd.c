/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 23:24:08 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/28 21:10:29 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	ft_pwd(void)
{
	char	*cwd;

	cwd = ft_getenv("PWD");
	if (!cwd)
	{
		if ((cwd = get_working_dir("pwd")))
			ft_putendl_fd(cwd, STDOUT);
		free(cwd);
	}
	else
		ft_putendl_fd(cwd, STDOUT);
	g_status = EXIT_SUCCESS;
	return (1);
}
