/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:13:49 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/19 12:50:59 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** SELF-MADE HEADER FILES
*/

# include "libft.h"
# include "parse.h"
# include "read.h"
# include "token.h"
# include "utils.h"

/*
** EXTERNAL LIBRARIES
*/

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

/*
** MACRO DECLARATION - LOOP STATUS
*/

# define EXIT_LOOP 0
# define STAY_LOOP 1

#endif
