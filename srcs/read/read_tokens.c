/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:30:29 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/26 17:34:27 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	split_tokens(t_list **tokens, char *line)
{
}

t_list	*read_tokens(void)
{
	char	*line;
	t_list	*tokens;

	read_arg(&line);
	split_tokens(&tokens, line);
}
