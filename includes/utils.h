/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:30:32 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/19 02:10:16 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"
# include "minishell.h"
# include "token.h"
# include <errno.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	clear_tokens(t_token **tokens);
void	exit_perror(char *err_msg, int exit_status);
int		token_size(t_token *tokens);
char	*ft_getenv(const char *name);
void	ft_perror(char *s);
int		ft_putenv(const char *string);
int		ft_setenv(const char *name, const char *value, int overwrite);
int		ft_unsetenv(const char *name);
void	put_prompt(void);
t_token	*dlistnew(char *src, int sep);
t_token	*dlisthead(t_token *tokens);
t_token	*dlistlast(t_token *tokens);
void	dlist_add_back(t_token **list, t_token *new);
void	signal_handler(int sig);
void	signal_ignore(int sig);
int		get_next_input(int fd, char **line);

#endif
