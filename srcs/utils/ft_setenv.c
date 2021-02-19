/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 09:51:45 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/20 00:58:09 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char	*double_strjoin(const char *name, const char *value)
{
	char	*new;
	char	*tmp;

	if (!(tmp = ft_strjoin(name, "=")))
		exit_perror("ft_setenv", EXIT_FAILURE);
	if (!(new = ft_strjoin(tmp, value)))
		exit_perror("ft_setenv", EXIT_FAILURE);
	ft_free(tmp);
	return (new);
}

static int	overwrite(const char *name, const char *value, int index)
{
	char	*new;

	new = double_strjoin(name, value);
	ft_free(g_env[index]);
	g_env[index] = new;
	return (0);
}

static int	reset(const char *name, const char *value, int len)
{
	char	**new_env;
	int		i;
	char	*new;

	if (!(new_env = ft_calloc(len + 2, sizeof(char*))))
		exit_perror("ft_setenv", EXIT_FAILURE);
	i = 0;
	while (g_env[i])
	{
		new_env[i] = g_env[i];
		i++;
	}
	ft_free(g_env);
	g_env = new_env;
	if (value)
		new = double_strjoin(name, value);
	else
	{
		if (!(new = ft_strdup(name)))
			exit_perror("ft_setenv", EXIT_FAILURE);
	}
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
