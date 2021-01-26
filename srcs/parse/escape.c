/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:01:14 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/25 11:38:24 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*parse_esc(char *src)
{
	char	*ret;
	int		i;
	int		j;

	if (!(ret = ft_calloc(sizeof(char), ft_strlen(src))))
		return (NULL);
	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] == '\\')
		{
			ret[j] = ft_parse_esc(src + i);
			j++;
			i += 2;
		}
		else
			ret[j++] = src[i++];
	}
	return (ret);
}

void	convert_esc(char **args)
{
	int	i;
	char	*tmp;

	i = 0;
	while (args[i])
	{
		if (ft_strchr(args[i], '\\'))
		{
			tmp = args[i];
			args[i] = parse_esc(tmp);
			ft_free(tmp);
		}
		i++;
	}
}
