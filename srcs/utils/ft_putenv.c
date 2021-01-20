/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 21:30:12 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/20 15:27:50 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_putenv(const char *string)
{
	char	*tmp;

	if (!string || !(tmp = ft_strchr(string, '=')))
	{
		errno = EINVAL;
		return (-1);
	}
	*tmp = '\0';
	return (ft_setenv(string, tmp + 1, 1));
}
