/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 23:26:45 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/23 04:50:02 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	ft_unset(char **args)
{
	int	is_error;
	int	i;

	is_error = 0;
	i = 1;
	while (args[i])
	{
		if (ft_unsetenv(args[i]) == INVALID_NAME)
		{
			is_error = 1;
			g_status = EXIT_FAILURE;
			errno = E_VALID;
			ft_putstr_fd("minish: unset: `", STDERR);
			ft_putstr_fd(args[i], STDERR);
			ft_putstr_fd("'", STDERR);
			ft_perror("");
		}
		i++;
	}
	if (!is_error)
		g_status = EXIT_SUCCESS;
	return (1);
}
