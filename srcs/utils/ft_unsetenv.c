/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 20:20:28 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/13 13:41:07 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_unsetenv(const char *name, int namelen)
{
	int		envlen;
	int		i;
	int		j;
	char	**new;

	envlen = 0;
	while (g_env[envlen])
		envlen++;
	if (!(new = ft_calloc(envlen, sizeof(char*))))
		return (-1);
	i = 0;
	j = 0;
	while (g_env[i])
	{
		if (!ft_strncmp(name, g_env[i], namelen))
			ft_free(g_env[i++]);
		else
			new[j++] = g_env[i++];
	}
	ft_free(g_env);
	g_env = new;
	return (0);
}

int			ft_unsetenv(const char *name)
{
	int	i;
	int	namelen;

	if (!name || !(namelen = ft_strlen(name)) || ft_strchr(name, '='))
	{
		errno = EINVAL;
		return (-1);
	}
	i = 0;
	while (g_env[i])
	{
		if (!ft_strncmp(name, g_env[i], namelen))
			return (_unsetenv(name, namelen));
		i++;
	}
	return (0);
}
