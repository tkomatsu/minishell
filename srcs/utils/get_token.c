/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 10:58:56 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/01 16:20:31 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_token(char *s, char *delim)
{
	static char	*last;
	char		*quote;
	char		*dquote;

	if (!s && !(s = last))
		return (NULL);
	while (*s && ft_strchr(delim, *s))
		s++;
	quote = ft_strchr(s, '\'');
	dquote = ft_strchr(s, '\"');
	if (quote || dquote)
	{
		if ((quote && dquote && (dquote - quote) > 0) || (quote && !dquote))
		{
			*quote = ' ';
			ft_strtok(quote + 1, "\'");
		}
		else
		{
			*dquote = ' ';
			ft_strtok(dquote + 1, "\"");
		}
		return (s);
	}
	else
		return (ft_strtok_r(s, delim, &last));
}
