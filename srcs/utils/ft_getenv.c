/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:54:18 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/26 17:31:27 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
		if (!ft_strncmp(name, g_env[i], namelen) && g_env[i][namelen] == '=')
			return (&(g_env[i][namelen - 1]));
		i++;
	}
	return (NULL);
}
