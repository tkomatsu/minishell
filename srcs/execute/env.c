/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:11:50 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/19 03:41:44 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	msh_env(void)
{
	int			i;

	i = 0;
	while (g_env[i])
	{
		if (ft_strchr(g_env[i], '='))
			ft_putendl_fd(g_env[i], STDOUT);
		i++;
	}
	return (STAY_LOOP);
}
