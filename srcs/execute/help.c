/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:51:35 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/26 21:47:50 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

const char	*strs[] = {"When executing interactively, bash displays the primary "
						"prompt PS1 when\n",
						"it is ready to read a command, and the secondary  "
						"prompt  PS2  when  it\n",
						"needs  more  input  to  complete  a  command.  Bash "
						"allows these prompt\n",
						"strings to be customized by inserting  a  number  of  "
						"backslash-escaped\n",
						"special characters that are decoded as follows: \n\n",
						"	\\a	an ASCII bell character(07)\n",
						"	\\n	newline\n",
						"	\\s	the name of the shell\n",
						"	\\u	the username of the current user\n",
						"	\\v	the version of bash(e.g., 2.00)\n",
						"	\\V	the release of bash, version + patch level(e.g., "
						"2.00.0)\n",
						"	\\w	the current working directory, with $HOME "
						"abbreviated with a tilde\n",
						"	\\W	the basename of the current working directory, "
						"with $HOME ",
						"abbreviated with a tilde\n",
						"	\\\\	a backslash\n",
						NULL};

static void	help_prompt(void)
{
	int	i;

	i = 0;
	while (strs[i])
		ft_putstr_fd((char *)strs[i++], STDOUT);
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
