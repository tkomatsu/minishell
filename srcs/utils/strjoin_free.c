/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:52:50 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/24 14:54:07 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*strjoin_free(char *new, char *str)
{
	char	*ret;

	if(!(ret = ft_strjoin(new, str)))
		exit_perror("strjoin_free", EXIT_FAILURE);
	ft_free(new);
	ft_free(str);
	return (ret);
}
