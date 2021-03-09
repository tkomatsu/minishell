/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 22:24:24 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/03/09 12:30:16 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	execmd(int argc, char **argv)
{
	if (!argv[0])
		return (STAY_LOOP);
	else if (!ft_strcmp(argv[0], "echo"))
		return (ft_echo(argv));
	else if (!ft_strcmp(argv[0], "cd"))
		return (ft_cd(argc, argv));
	else if (!ft_strcmp(argv[0], "pwd"))
		return (ft_pwd());
	else if (!ft_strcmp(argv[0], "export"))
		return (ft_export(argv));
	else if (!ft_strcmp(argv[0], "unset"))
		return (ft_unset(argv));
	else if (!ft_strcmp(argv[0], "env"))
		return (ft_env(argc));
	else if (!ft_strcmp(argv[0], "exit"))
		return (ft_exit(argv));
	else if (!ft_strcmp(argv[0], "help"))
		return (help(argv));
	else if (is_ultimate_question(argv))
		return (STAY_LOOP);
	return (launch(argv));
}
