/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 21:30:12 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/20 00:09:04 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_putenv(const char *string)
{
	char	*tmp;
	int		i;

	i = 0;
	if (ft_isdigit(string[i]) || string[i] == '=')
		return (INVALID_NAME);
	if ((tmp = ft_strchr(string, '=')))
		*(tmp++) = '\0';
	while (string[i])
	{
		if (!ft_isalnum(string[i]) && string[i] != '_')
			return (INVALID_NAME);
		i++;
	}
	return (ft_setenv(string, tmp, 1));
}
