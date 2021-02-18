/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:10:08 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/19 02:11:32 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

/*
** TYPE
*/

# define WORD 1
# define NEWLINE 2
# define PIPE 3
# define AND 4
# define SEMICOLON 5
# define P_OPEN 6
# define P_CLOSE 7
# define GREATER 8
# define LESS 9

/*
** STRUCTURE
*/

typedef struct	s_token
{
	char			*word;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}				t_token;

#endif
