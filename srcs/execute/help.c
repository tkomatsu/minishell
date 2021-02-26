/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:51:35 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/26 22:19:24 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static void	help_prompt(void)
{
	ft_putstr_fd("When executing interactively, bash displays", STDOUT);
	ft_putstr_fd(" the primary prompt PS1 when\n", STDOUT);
	ft_putstr_fd("it is ready to read a command, and the secondary", STDOUT);
	ft_putstr_fd("  prompt  PS2  when  it\n", STDOUT);
	ft_putstr_fd("needs  more  input  to  complete  a  command.", STDOUT);
	ft_putstr_fd("  Bash allows these prompt\n", STDOUT);
	ft_putstr_fd("strings to be customized by inserting  a  number", STDOUT);
	ft_putstr_fd("  of  backslash-escaped\n", STDOUT);
	ft_putstr_fd("special characters that are decoded as follows:", STDOUT);
	ft_putstr_fd(" \n\n	\\a	an ASCII bell character(07)\n", STDOUT);
	ft_putstr_fd("	\\n	newline\n	\\s	the name of the shell\n", STDOUT);
	ft_putstr_fd("	\\u	the username of the current user\n", STDOUT);
	ft_putstr_fd("	\\v	the version of bash(e.g., 2.00)\n", STDOUT);
	ft_putstr_fd("	\\V	the release of bash, version + patch ", STDOUT);
	ft_putstr_fd("level(e.g., 2.00.0)\n", STDOUT);
	ft_putstr_fd("	\\w	the current working directory, with $HOME", STDOUT);
	ft_putstr_fd(" abbreviated with a tilde\n", STDOUT);
	ft_putstr_fd("	\\W	the basename of the current working ", STDOUT);
	ft_putstr_fd("directory, with $HOME abbreviated with a tilde\n", STDOUT);
	ft_putstr_fd("	\\\\	a backslash\n", STDOUT);
}

int			help(char **args)
{
	if (!args[1])
		ft_putendl_fd("Usage: help prompt or help ultimate", STDOUT);
	else if (!ft_strcasecmp(args[1], "prompt"))
		help_prompt();
	else if (!ft_strcasecmp(args[1], "deepthought"))
	{
		ft_putstr_fd("Answer to the Ultimate Question of Life, ", STDOUT);
		ft_putstr_fd("the Universe, and Everything\n", STDOUT);
	}
	return (STAY_LOOP);
}
