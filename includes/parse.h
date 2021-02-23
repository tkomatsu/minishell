/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:26:49 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/24 04:31:49 by kefujiwa         ###   ########.fr       */
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
** PROTOTYPE DECLARATION
*/
int		run_cmd(void *content, int flag);
int		run_pipeline(t_list *lst);
int		parse_exec(t_token *tokens);
void	expand_tokens(void *content);
char	*expand_quotes(char *str, char **ptr);
char	*expand_dquotes(char *str, char **ptr);
char	*expand_words(char *str, char **ptr);
char	**token_to_args(t_token *tokens);

int		set_redirect(t_token *token);

#endif
