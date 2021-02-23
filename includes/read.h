/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:23:22 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/24 03:20:43 by kefujiwa         ###   ########.fr       */
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
char	*convert_dquotes(char *str, char **ptr);
char	*convert_quotes(char *str, char **ptr);
char	*convert_words(char *str, char **ptr);
char	*expand_environ(char *str, char *new, char **head, char **ptr);
int		get_next_input(int fd, char **line);
void	parse_line(char **line);
int		read_stdin(char **line);
t_token	*tokenize(char *line);

#endif
