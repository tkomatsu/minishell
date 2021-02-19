/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 23:26:45 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/19 03:34:38 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	msh_unset(char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (ft_unsetenv(args[i]) == -1)
		{
			g_status = EXIT_FAILURE;
			errno = E_VALID;
			ft_putstr_fd("minish: unset: `", STDERR);
			ft_putstr_fd(args[i], STDERR);
			ft_putstr_fd("'", STDERR);
			ft_perror("");
		}
		i++;
	}
	return (1);
}
