/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:29:24 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/13 20:10:57 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_varlen(char *p_str)
{
	int	len;

	len = 0;
	if (ft_isdigit(*p_str) || *p_str == '?')
		return (1);
	while (ft_isalnum(*p_str) || *p_str == '_')
	{
		len++;
		p_str++;
	}
	return (len);
}

static char	*get_var(char *p_str, int len)
{
	char	*tmp;
	char	*env;
	char	*ret;

	if (!(tmp = ft_substr(p_str, 0, len)))
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

static char	*deploy_var(char *p_str, int len)
{
	char	*ret;

	if (len == 0)
	{
		if (!(ret = ft_strdup("$")))
			return (NULL);
	}
	else if (len == 1 && *p_str == '?')
	{
		if (!(ret = ft_strdup(ft_itoa(g_status))))
			return (NULL);
	}
	else
	{
		if (!(ret = get_var(p_str, len)))
			return (NULL);
	}
	return (ret);
}

char		*parse_var(char *p_str, char **str, char **new)
{
	char	*tmp;
	char	*var;
	int		len;

	if (!(tmp = ft_strjoin(*new, *str)))
		return (NULL);
	ft_free(*new);
	*new = tmp;
	len = get_varlen(p_str);
	if (!(var = deploy_var(p_str, len)))
		return (NULL);
	if (!(tmp = ft_strjoin(*new, var)))
		return (NULL);
	ft_free(var);
	ft_free(*new);
	*new = tmp;
	*str = p_str + len;
	return (p_str + len - 1);
}