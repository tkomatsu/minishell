/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:38:30 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/03/07 11:38:29 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void putversion(char c)
{
	if (c == 'v' || c == 'V')
	{
		ft_putstr_fd(VERSION, STDERR);
		if (c == 'V')
			ft_putstr_fd(PATCHVERSION, STDERR);
	}
}

static void	putdir(char c)
{
	char	*home;
	char	*cwd;
	int		len;

	if (!(cwd = ft_getenv("PWD")))
		return ;
	if (c == 'w')
	{
		if (!(home = ft_getenv("HOME")))
			return ;
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
		cwd = ft_strrchr(cwd, '/');
		ft_putstr_fd(cwd + 1, STDERR);
	}
}

static void	putstatus(char c)
{
	char	*exit_status;

	if (c == 'x')
	{
		if (!(exit_status = ft_itoa(g_status)))
			exit_perror("ft_itoa", EXIT_FAILURE);
		ft_putstr_fd(exit_status, STDERR);
		free(exit_status);
	}
}

static void	putformat(char c)
{
	if (c == 'a')
		ft_putchar_fd('\a', STDERR);
	else if (c == 'n')
		ft_putchar_fd('\n', STDERR);
	else if (c == 's')
		ft_putstr_fd("minish", STDERR);
	else if (c == 'u')
		ft_putstr_fd(ft_getenv("USER"), STDERR);
	else if (c == 'v' || c == 'V')
		putversion(c);
	else if (c == 'w' || c == 'W')
		putdir(c);
	else if (c == 'x')
		putstatus(c);
	else if (c == '\\')
		ft_putchar_fd('\\', STDERR);
	else
	{
		ft_putchar_fd('\\', STDERR);
		ft_putchar_fd(c, STDERR);
	}
}

void		put_prompt(char *ps)
{
	char	*format;

	if (!(format = ft_getenv(ps)))
	{
		if (!strcmp(ps, "PS1"))
			ft_putstr_fd("minishell$ ", STDERR);
		else if (!strcmp(ps, "PS2"))
			ft_putstr_fd("> ", STDERR);
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
