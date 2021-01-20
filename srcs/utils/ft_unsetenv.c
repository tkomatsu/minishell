/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 20:20:28 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/20 20:58:52 by tkomatsu         ###   ########.fr       */
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
	if (!(new = ft_calloc(sizeof(char *), envlen)))
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
