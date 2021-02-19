/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 20:20:28 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/20 00:28:11 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	delete_env(const char *name, int namelen)
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

	if (!(namelen = ft_strlen(name)))
		return (0);
	i = 0;
	if (ft_isdigit(name[i]))
		return (INVALID_NAME);
	while (name[i])
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (INVALID_NAME);
		i++;
	}
	i = 0;
	while (g_env[i])
	{
		if (!ft_strncmp(name, g_env[i], namelen))
			return (delete_env(name, namelen));
		i++;
	}
	return (0);
}
