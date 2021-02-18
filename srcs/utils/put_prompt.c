/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:38:30 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/18 19:47:27 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	putdir(char c)
{
	char	*home;
	char	*cwd;
	int		len;

	if (c == 'w')
	{
		home = ft_getenv("HOME");
		cwd = ft_getenv("PWD");
		len = ft_strlen(home);
		if (ft_strncmp(home, cwd, len))
			ft_putstr_fd(cwd, 2);
		else
		{
			ft_putchar_fd('~', 2);
			ft_putstr_fd(cwd + len, 2);
		}
	}
}

static void	putformat(char c)
{
	if (c == 'a')
		ft_putchar_fd('\a', 2);
	else if (c == 'n')
		ft_putchar_fd('\n', 2);
	else if (c == 's')
		ft_putstr_fd("minishell", 2);
	else if (c == 'u')
		ft_putstr_fd(ft_getenv("USER"), 2);
	else if (c == 'w')
		putdir(c);
	else if (c == '\\')
		ft_putchar_fd('\\', 2);
	else
	{
		ft_putchar_fd('\\', 2);
		ft_putchar_fd(c, 2);
	}
}

void		put_prompt(void)
{
	char	*format;

	if (!(format = ft_getenv("PS1")))
	{
		ft_putstr_fd("minishell$ ", 2);
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
			ft_putchar_fd(*format, 2);
		format++;
	}
}
