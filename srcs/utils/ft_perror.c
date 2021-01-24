/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 23:36:39 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/24 22:51:25 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_strerror(void)
{
	char *str;

	if (!(str = ft_calloc(sizeof(char*), 100)))
		return (NULL);
	if (errno == 201)
		ft_strlcpy(str, "command not found", 100);
	else
		ft_strlcpy(str, "undefine error", 100);
	return (str);
}

void	ft_perror(char *s)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd(": ", 2);
	if (200 <= errno && errno < 299)
		ft_putstr_fd(ft_strerror(), 2);
	else
		ft_putstr_fd(strerror(errno), 2);
	ft_putchar_fd('\n', 2);
}
