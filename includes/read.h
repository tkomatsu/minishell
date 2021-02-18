/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:23:22 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/19 02:14:00 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

# include "libft.h"
# include "minishell.h"
# include "utils.h"

/*
** FLAG: QUOTE:0b0001, DQUOTE:0b0010, ESC:0b0100
*/

# define QUOTE 0x01
# define DQUOTE 0x02
# define ESC 0x04

int		read_stdin(char **line);
t_token	*split_tokens(char *line);

#endif
