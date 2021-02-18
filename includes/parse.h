/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:26:49 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/19 03:01:16 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "execute.h"
# include "libft.h"
# include "minishell.h"
# include "parse.h"
# include "token.h"
# include "utils.h"
# include <fcntl.h>
# include <sys/wait.h>

/*
** TYPE OF CONVERT
*/

# define T_QUOTE 1
# define T_DQUOTE 2
# define T_WORDS 3

char	**convert_lst_to_args(t_token *tokens);
char	*convert_quotes(char *str, char **ptr);
char	*convert_dquotes(char *str, char **ptr);
char	*convert_words(char *str, char **ptr);
int		ft_lstiter_sta(t_list *lst, int (*f)(void *));
int		parse_exec(t_token *tokens);
int		parse_pipe(void *content);
char	*parse_tokens(t_token *tokens);
char	*parse_var(char *str, char *new, char **head, char **ptr);

#endif
