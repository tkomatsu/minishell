/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:38:30 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/07 18:11:15 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	putformat(char c)
{
	char	*home;
	char	*cwd;
	int		len;

	if (c == 'u')
		ft_putstr_fd(ft_getenv("USER"), 1);
	else if (c == 'w')
	{
		home = ft_getenv("HOME");
		cwd = ft_getenv("PWD");
		len = ft_strlen(home);
		if (ft_strncmp(home, cwd, len))
			ft_putstr_fd(cwd, 1);
		else
		{
			ft_putchar_fd('~', 1);
			ft_putstr_fd(cwd + len, 1);
		}
	}
	else
	{
		ft_putchar_fd('\\', 1);
		ft_putchar_fd(c, 1);
	}
}

void	put_prompt(void)
{
	char	*format;

	if (!(format = ft_getenv("PS1")))
	{
		ft_putstr_fd("minishell$ ", 1);
		return ;
	}
	while (*format)
	{
		if (*format == '\\' && *(format + 1))
		{
			format++;
			putformat(*format);
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
}
