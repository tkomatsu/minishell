/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ultimate_question.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 10:17:27 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/27 14:20:53 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easter.h"

static int	put_answer(void)
{
	ft_putendl_fd(" _  _ ___", STDOUT);
	ft_putendl_fd("| || |__ \\", STDOUT);
	ft_putendl_fd("| || |_ ) |", STDOUT);
	ft_putendl_fd("|__   _/ /", STDOUT);
	ft_putendl_fd("   | |/ /_", STDOUT);
	ft_putendl_fd("   |_|____|", STDOUT);
	return (1);
}

int			is_ultimate_question(char **str)
{
	if (!str[0] || ft_strcasecmp(str[0], "Answer"))
		return (0);
	if (!str[1] || ft_strcasecmp(str[1], "to"))
		return (0);
	if (!str[2] || ft_strcasecmp(str[2], "the"))
		return (0);
	if (!str[3] || ft_strcasecmp(str[3], "Ultimate"))
		return (0);
	if (!str[4] || ft_strcasecmp(str[4], "Question"))
		return (0);
	if (!str[5] || ft_strcasecmp(str[5], "of"))
		return (0);
	if (!str[6] || ft_strcasecmp(str[6], "Life,"))
		return (0);
	if (!str[7] || ft_strcasecmp(str[7], "the"))
		return (0);
	if (!str[8] || ft_strcasecmp(str[8], "Universe,"))
		return (0);
	if (!str[9] || ft_strcasecmp(str[9], "and"))
		return (0);
	if (!str[10] || ft_strcasecmp(str[10], "Everything"))
		return (0);
	if (!str[11])
		return (put_answer());
	return (0);
}
