/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ultimate_question.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 10:17:27 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/18 21:13:59 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easter.h"

int	is_ultimate_question(char **str)
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
	if (str[11])
		return (0);
	write(1, "42\n", 3);
	return (1);
}
