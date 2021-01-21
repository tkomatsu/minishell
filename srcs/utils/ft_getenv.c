/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:54:18 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/19 22:31:03 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_getenv(const char *name)
{
	int	i;
	int	namelen;

	if (!name || !(namelen = ft_strlen(name)) || ft_strchr(name, '='))
	{
		errno = EINVAL;
		return (NULL);
	}
	i = 0;
	while (g_env[i])
	{
		if (!ft_strncmp(name, g_env[i], namelen))
			return (&(g_env[i][namelen + sizeof("=") - 1]));
		i++;
	}
	return (NULL);
}
