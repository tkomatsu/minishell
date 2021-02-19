/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 23:36:39 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/20 00:00:32 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char	*ft_strerror(void)
{
	char *str;

	if (!(str = ft_calloc(100, sizeof(char*))))
		exit_perror("ft_strerror", EXIT_FAILURE);
	if (errno == E_MINI)
		ft_strlcpy(str, "minishell error", 100);
	else if (errno == E_CMD)
		ft_strlcpy(str, "command not found", 100);
	else if (errno == E_QUOTE)
		ft_strlcpy(str, "no closing quotation", 100);
	else if (errno == E_VALID)
		ft_strlcpy(str, "not a valid identifier", 100);
	else if (errno == E_NUMERIC)
		ft_strlcpy(str, "numeric argument required", 100);
	else if (errno == E_ARGS)
		ft_strlcpy(str, "too many arguments", 100);
	else
		ft_strlcpy(str, "undefine error", 100);
	return (str);
}

void		ft_perror(char *s)
{
	char	*err_msg;

	ft_putstr_fd(s, STDERR);
	ft_putstr_fd(": ", STDERR);
	if (200 <= errno && errno < 299)
	{
		ft_putstr_fd((err_msg = ft_strerror()), STDERR);
		ft_free(err_msg);
	}
	else
		ft_putstr_fd(strerror(errno), STDERR);
	ft_putchar_fd('\n', STDERR);
}
