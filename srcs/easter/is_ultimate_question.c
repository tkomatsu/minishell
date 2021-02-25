/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ultimate_question.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 10:17:27 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/25 15:51:14 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easter.h"

static int	put_answer(char **str)
{
	if (str[11])
		return (0);
	write(STDOUT, "42\n", 3);
	return (1);
}

int			is_ultimate_question(char **str)
{
	if (ft_strcasecmp(str[0], "Answer"))
		return (0);
	if (ft_strcasecmp(str[1], "to"))
		return (0);
	if (ft_strcasecmp(str[2], "the"))
		return (0);
	if (ft_strcasecmp(str[3], "Ultimate"))
		return (0);
	if (ft_strcasecmp(str[4], "Question"))
		return (0);
	if (ft_strcasecmp(str[5], "of"))
		return (0);
	if (ft_strcasecmp(str[6], "Life,"))
		return (0);
	if (ft_strcasecmp(str[7], "the"))
		return (0);
	if (ft_strcasecmp(str[8], "Universe,"))
		return (0);
	if (ft_strcasecmp(str[9], "and"))
		return (0);
	if (ft_strcasecmp(str[10], "Everything"))
		return (0);
	return (put_answer(str));
}
