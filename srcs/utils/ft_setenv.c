/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 09:51:45 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/20 22:08:19 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_overwrite(const char *name, const char *value, int index)
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

static int	_reset(const char *name, const char *value, int len)
{
	char	**new_env;
	int		i;
	char	*new;
	char	*tmp;

	if (!(new_env = ft_calloc(sizeof(char*), (len + 2))))
		return (-1);
	i = 0;
	while (g_env[i])
	{
		new_env[i] = g_env[i];
		i++;
	}
	ft_free(g_env);
	g_env = new_env;
	tmp = ft_strjoin(name, "=");
	new = ft_strjoin(tmp, value);
	ft_free(tmp);
	g_env[i] = new;
	return (0);
}

int			ft_setenv(const char *name, const char *value, int overwrite)
{
	int			i;
	int			namelen;
	int			valuelen;

	if (!name || !(namelen = ft_strlen(name)))
	{
		errno = EINVAL;
		return (-1);
	}
	i = 0;
	valuelen = ft_strlen(value);
	while (g_env[i])
	{
		if (!ft_strncmp(name, g_env[i], namelen))
		{
			if (overwrite)
				return (_overwrite(name, value, i));
			else
				return (0);
		}
		i++;
	}
	return (_reset(name, value, i));
}
