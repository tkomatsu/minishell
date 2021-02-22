/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:26:49 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/22 11:45:46 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

/*
** SELF-MADE HEADER FILES
*/
# include "execute.h"
# include "libft.h"
# include "token.h"
# include "utils.h"

/*
** EXTERNAL LIBRARIES
*/
# include <fcntl.h>
# include <sys/wait.h>

/*
** MACRO DECLARATION - TYPE OF CONVERT
*/
# define T_QUOTE 1
# define T_DQUOTE 2
# define T_WORDS 3

/*
** PROTOTYPE DECLARATION
*/
int		run_cmd(void *content, int flag);
int		run_pipeline(t_list *lst);
int		parse_exec(t_token *tokens);
void	expand_token(void *content);
char	*expand_environ(char *str, char *new, char **head, char **ptr);
char	**token_to_args(t_token *tokens);
void	convert_esc(char **args);
char	*convert_quotes(char *str, char **ptr);
char	*convert_dquotes(char *str, char **ptr);
char	*convert_words(char *str, char **ptr);

void	set_redirect(t_token *token);

#endif
