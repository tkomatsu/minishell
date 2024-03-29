/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 20:20:28 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/03/04 09:11:03 by tkomatsu         ###   ########.fr       */
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
		exit_perror("delete_env", EXIT_FAILURE);
	i = 0;
	j = 0;
	while (g_env[i])
	{
		if (!ft_strncmp(name, g_env[i], namelen)
				&& (g_env[i][namelen] == '=' || g_env[i][namelen] == '\0'))
			free(g_env[i++]);
		else
			new[j++] = g_env[i++];
	}
	free(g_env);
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
		if (!ft_strncmp(name, g_env[i], namelen)
				&& (g_env[i][namelen] == '=' || g_env[i][namelen] == '\0'))
			return (delete_env(name, namelen));
		i++;
	}
	return (0);
}
