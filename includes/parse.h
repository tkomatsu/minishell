/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:26:49 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/19 14:18:11 by tkomatsu         ###   ########.fr       */
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
int		run_pipeline(t_list *lst, int (*f)(void *, int));
int		parse_exec(t_token *tokens);
void	exp_word(void *content);
char	*parse_var(char *str, char *new, char **head, char **ptr);
char	**token_to_args(t_token *tokens);
void	convert_esc(char **args);
char	*convert_quotes(char *str, char **ptr);
char	*convert_dquotes(char *str, char **ptr);
char	*convert_words(char *str, char **ptr);

/*
char	**convert_lst_to_args(t_token *tokens);
char	*convert_quotes(char *str, char **ptr);
char	*convert_dquotes(char *str, char **ptr);
char	*convert_words(char *str, char **ptr);
int		ft_lstiter_sta(t_list *lst, int (*f)(void *));
int		parse_exec(t_token *tokens);
int		parse_pipe(void *content);
char	*parse_tokens(t_token *tokens);
char	*parse_var(char *str, char *new, char **head, char **ptr);
*/

#endif
