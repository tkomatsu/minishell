/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 21:30:12 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/13 20:24:22 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_putenv(const char *string)
{
	char	*tmp;
	int		i;

	i = 0;
	if (ft_isdigit(string[i]))
		return (-1);
	if (!(tmp = ft_strchr(string, '=')))
		return (0);
	*tmp = '\0';
	while (string[i])
	{
		if (!ft_isalnum(string[i]) && string[i] != '_')
			return (-1);
		i++;
	}
	return (ft_setenv(string, tmp + 1, 1));
}
