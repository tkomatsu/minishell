/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 22:34:03 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/18 22:45:02 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	read_arg(char **line)
{
	int	ret;

	if ((ret = get_next_line(0, line)) < 0)
	{
		perror("get_next_line");
		exit(1);
	}
	return (0);
}
