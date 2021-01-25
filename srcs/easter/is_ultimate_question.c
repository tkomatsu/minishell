/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ultimate_question.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 10:17:27 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/25 13:13:09 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_ultimate_question(char **str)
{
	if (ft_strcmp(str[0], "Answer"))
		return (0);
	if (ft_strcmp(str[1], "to"))
		return (0);
	if (ft_strcmp(str[2], "the"))
		return (0);
	if (ft_strcmp(str[3], "Ultimate"))
		return (0);
	if (ft_strcmp(str[4], "Question"))
		return (0);
	if (ft_strcmp(str[5], "of"))
		return (0);
	if (ft_strcmp(str[6], "Life,"))
		return (0);
	if (ft_strcmp(str[7], "the"))
		return (0);
	if (ft_strcmp(str[8], "Universe,"))
		return (0);
	if (ft_strcmp(str[9], "and"))
		return (0);
	if (ft_strcmp(str[10], "Everything"))
		return (0);
	if (str[11])
		return (0);
	write(1, "42\n", 3);
	return (1);
}
