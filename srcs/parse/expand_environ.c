/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_environ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:29:24 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/02/25 16:48:35 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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
		exit_perror("get_var", EXIT_FAILURE);
	if (!(env = ft_getenv(tmp)))
	{
		if (!(ret = ft_strdup("")))
			exit_perror("get_var", EXIT_FAILURE);
	}
	else
	{
		if (!(ret = ft_strdup(env)))
			exit_perror("get_var", EXIT_FAILURE);
	}
	free(tmp);
	return (ret);
}

static char	*deploy_var(char *str, int len)
{
	char	*ret;

	if (len == 0)
	{
		if (!(ret = ft_strdup("$")))
			exit_perror("deploy_var", EXIT_FAILURE);
	}
	else if (len == 1 && *str == '?')
	{
		if (!(ret = ft_strdup(ft_itoa(g_status))))
			exit_perror("deploy_var", EXIT_FAILURE);
	}
	else
		ret = get_var(str, len);
	return (ret);
}

char		*expand_environ(char *str, char *new, char **head, char **ptr)
{
	char	*tmp;
	char	*var;
	int		len;

	if (!(tmp = ft_strjoin(new, *head)))
		exit_perror("expand_environ", EXIT_FAILURE);
	free(new);
	new = tmp;
	len = get_varlen(str);
	var = deploy_var(str, len);
	if (!(tmp = ft_strjoin(new, var)))
		exit_perror("expand_environ", EXIT_FAILURE);
	free(var);
	free(new);
	new = tmp;
	*head = str + len;
	*ptr = str + len - 1;
	return (new);
}
