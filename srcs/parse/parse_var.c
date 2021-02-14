/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:29:24 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/14 15:20:53 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_varlen(char *str)
{
	int	len;

	len = 0;
	if (ft_isdigit(*str) || *str == '?')
		return (1);
	while (ft_isalnum(*str) || *str == '_')
	{
		len++;
		str++;
	}
	return (len);
}

static char	*get_var(char *str, int len)
{
	char	*tmp;
	char	*env;
	char	*ret;

	if (!(tmp = ft_substr(str, 0, len)))
		return (NULL);
	if (!(env = ft_getenv(tmp)))
	{
		ft_free(tmp);
		if (!(ret = ft_strdup("")))
			return (NULL);
	}
	else
	{
		ft_free(tmp);
		if (!(ret = ft_strdup(ft_getenv(tmp))))
			return (NULL);
	}
	return (ret);
}

static char	*deploy_var(char *str, int len)
{
	char	*ret;

	if (len == 0)
	{
		if (!(ret = ft_strdup("$")))
			return (NULL);
	}
	else if (len == 1 && *str == '?')
	{
		if (!(ret = ft_strdup(ft_itoa(g_status))))
			return (NULL);
	}
	else
	{
		if (!(ret = get_var(str, len)))
			return (NULL);
	}
	return (ret);
}

char		*parse_var(char *str, char **head, char **new)
{
	char	*tmp;
	char	*var;
	int		len;

	if (!(tmp = ft_strjoin(*new, *head)))
		return (NULL);
	ft_free(*new);
	*new = tmp;
	len = get_varlen(str);
	if (!(var = deploy_var(str, len)))
		return (NULL);
	if (!(tmp = ft_strjoin(*new, var)))
		return (NULL);
	ft_free(var);
	ft_free(*new);
	*new = tmp;
	*head = str + len;
	return (str + len - 1);
}
