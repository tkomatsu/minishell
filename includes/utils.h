/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:30:32 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/20 08:47:50 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*
** SELF-MADE HEADER FILES
*/

# include "error.h"
# include "libft.h"
# include "token.h"

/*
** EXTERNAL LIBRARIES
*/

# include <errno.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*
** MACRO DECLARATION - FILE DISCRIPTOR
*/

# define STDIN 0
# define STDOUT 1
# define STDERR 2

/*
** MACRO DECLARATION - LOOP STATUS
*/
# define EXIT_LOOP 0
# define STAY_LOOP 1

/*
** MACRO DECLARATION - RETURN VALUE
*/

# define INVALID_NAME -1

/*
** GLOBAL VARIABLES
*/

extern char		**g_env;
extern pid_t	g_pid;
extern int		g_status;

/*
** PROTOTYPE DECLARATION
*/

void	clear_tokens(t_token **tokens);
t_token	*dlistnew(char *src, int sep);
t_token	*dlisthead(t_token *tokens);
t_token	*dlistlast(t_token *tokens);
void	dlist_add_back(t_token **list, t_token *new);
void	exit_perror(char *err_msg, int exit_status);
char	*ft_getenv(const char *name);
void	ft_perror(char *s);
int		ft_putenv(const char *string);
int		ft_setenv(const char *name, const char *value, int overwrite);
int		ft_unsetenv(const char *name);
void	put_prompt(void);
void	signal_handler(int sig);
void	signal_ignore(int sig);
int		token_size(t_token *tokens);
int		get_next_input(int fd, char **line);

#endif
