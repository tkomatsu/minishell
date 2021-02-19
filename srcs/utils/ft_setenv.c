/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 09:51:45 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/18 19:46:58 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	overwrite(const char *name, const char *value, int index)
{
	char	*new;
	char	*tmp;

	tmp = ft_strjoin(name, "=");
	new = ft_strjoin(tmp, value);
	ft_free(tmp);
	ft_free(g_env[index]);
	g_env[index] = new;
	return (0);
}

static int	reset(const char *name, const char *value, int len)
{
	char	**new_env;
	int		i;
	char	*new;
	char	*tmp;

	if (!(new_env = ft_calloc(len + 2, sizeof(char*))))
		return (-1);
	i = 0;
	while (g_env[i])
	{
		new_env[i] = g_env[i];
		i++;
	}
	ft_free(g_env);
	g_env = new_env;
	if (value)
	{
		tmp = ft_strjoin(name, "=");
		new = ft_strjoin(tmp, value);
		ft_free(tmp);
	}
	else
		new = ft_strdup(name);
	g_env[i] = new;
	return (0);
}

int			ft_setenv(const char *name, const char *value, int is_overwrite)
{
	int			i;
	int			namelen;

	if (!name || !(namelen = ft_strlen(name)))
	{
		errno = EINVAL;
		return (INVALID_NAME);
	}
	i = 0;
	while (g_env[i])
	{
		if (!ft_strncmp(name, g_env[i], namelen))
		{
			if (is_overwrite)
				return (overwrite(name, value, i));
			else
				return (0);
		}
		i++;
	}
	return (reset(name, value, i));
}
