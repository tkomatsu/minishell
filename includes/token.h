/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:10:08 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/24 12:34:18 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "libft.h"
# include "utils.h"

/*
** MACRO DECLARATION - TYPE OF TOKEN
*/
# define WORD 1
# define NEWLINE 2
# define PIPE 3
# define AND 4
# define SEMICOLON 5
# define P_OPEN 6
# define P_CLOSE 7
# define GREATER 8
# define GREATER2 9
# define LESS 10

/*
** STRUCTURE
*/
typedef struct		s_token
{
	char			*word;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

void				del_token(t_token *token);
void				clear_tokens(t_token **tokens);
t_token				*dlistnew(char *src, int sep);
t_token				*dlisthead(t_token *tokens);
t_token				*dlistlast(t_token *tokens);
void				dlist_add_back(t_token **list, t_token *new);
void				dlstextract(t_token *token);
int					token_size(t_token *tokens);
int					syntax_check(t_token *token);

#endif
