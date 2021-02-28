/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_working_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 21:02:33 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/28 21:06:26 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*get_working_dir(char *whom)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		ft_putstr_fd(whom, STDERR);
		ft_putstr_fd(": error retrieving current directory: ", STDERR);
		ft_putstr_fd("getcwd: cannot access parent directories: ", STDERR);
		ft_putendl_fd(strerror(errno), STDERR);
		return (NULL);
	}
	return (cwd);
}
