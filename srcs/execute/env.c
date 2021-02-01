/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:11:50 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/22 23:27:23 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_env(void)
{
	int			i;

	i = 0;
	while (g_env[i])
		ft_putendl_fd(g_env[i++], 1);
	return (1);
}