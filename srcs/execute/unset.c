/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 23:26:45 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/13 20:30:18 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_unset(char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (ft_unsetenv(args[i]) == -1)
		{
			g_status = EXIT_FAILURE;
			errno = 203;
			ft_putstr_fd("minish: unset: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd("'", 2);
			ft_perror("");
		}
		i++;
	}
	return (1);
}
