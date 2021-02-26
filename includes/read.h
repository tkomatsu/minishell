/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:23:22 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/26 21:46:24 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

/*
** SELF-MADE HEADER FILES
*/
# include "error.h"
# include "libft.h"
# include "token.h"
# include "utils.h"

/*
** MACRO DECLARATION - BIT MASK FLAG
*/
# define QUOTE 0x01
# define DQUOTE 0x02
# define ESC 0x04

/*
** MACRO DECLARATION - INPUT STATUS
*/
# define VALID_INPUT 0
# define INVALID_INPUT 1

/*
** PROTOTYPE DECLARATION
*/
int		add_next_input(char **line, int *is_sigint);
int		get_next_input(char **line);
int		read_stdin(char **line);
t_token	*tokenize(char *line);

#endif
