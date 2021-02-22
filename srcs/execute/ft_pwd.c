/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 23:24:08 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/23 04:15:45 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	ft_pwd(void)
{
	ft_putendl_fd(ft_getenv("PWD"), STDOUT);
	g_status = EXIT_SUCCESS;
	return (1);
}
