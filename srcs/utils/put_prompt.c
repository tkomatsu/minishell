/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:38:30 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/20 22:38:39 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	putdir(char c)
{
	char	*home;
	char	*cwd;
	int		len;

	cwd = ft_getenv("PWD");
	if (c == 'w')
	{
		home = ft_getenv("HOME");
		len = ft_strlen(home);
		if (ft_strncmp(home, cwd, len))
			ft_putstr_fd(cwd, STDERR);
		else
		{
			ft_putchar_fd('~', STDERR);
			ft_putstr_fd(cwd + len, STDERR);
		}
	}
	else if (c == 'W')
	{
		while (*cwd)
			cwd++;
		while (*cwd != '/')
			cwd--;
		ft_putstr_fd(cwd + 1, STDERR);
	}
}

static void	putformat(char c)
{
	if (c == 'a')
		ft_putchar_fd('\a', STDERR);
	else if (c == 'n')
		ft_putchar_fd('\n', STDERR);
	else if (c == 's')
		ft_putstr_fd("minishell", STDERR);
	else if (c == 'u')
		ft_putstr_fd(ft_getenv("USER"), STDERR);
	else if (c == 'w' || c == 'W')
		putdir(c);
	else if (c == '\\')
		ft_putchar_fd('\\', STDERR);
	else
	{
		ft_putchar_fd('\\', STDERR);
		ft_putchar_fd(c, STDERR);
	}
}

void		put_prompt(void)
{
	char	*format;

	if (!(format = ft_getenv("PS1")))
	{
		ft_putstr_fd("minishell$ ", STDERR);
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
