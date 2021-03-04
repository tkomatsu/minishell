/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 23:25:58 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/03/04 22:41:01 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static int	cmp_content(void *a, void *b)
{
	return (ft_strcmp((char *)a, (char *)b));
}

static void	sort_ascii(t_list **env)
{
	t_list	*node;
	char	*content;
	int		i;

	*env = NULL;
	i = 0;
	while ((content = g_env[i++]))
	{
		if (!(node = ft_lstnew(content)))
			exit_perror("ft_export", EXIT_FAILURE);
		ft_lstadd_back(env, node);
	}
	ft_lstsort(env, cmp_content);
}

static void	export_item(char *item)
{
	ft_putstr_fd("declare -x ", STDOUT);
	while (*item && *item != '=')
		ft_putchar_fd(*(item++), STDOUT);
	if (*(item++) == '=')
		ft_putstr_fd("=\"", STDOUT);
	else
	{
		ft_putchar_fd('\n', STDOUT);
		return ;
	}
	while (*item)
	{
		if (*item == '$' || *item == '`' || *item == '\\' || *item == '"')
			ft_putchar_fd('\\', STDOUT);
		ft_putchar_fd(*(item++), STDOUT);
	}
	ft_putstr_fd("\"\n", STDOUT);
}

static void	export_list(void)
{
	t_list	*env;
	t_list	*head;

	sort_ascii(&env);
	head = env;
	while (env)
	{
		export_item(env->content);
		env = env->next;
	}
	ft_lstclear(&head, nop);
}

int			ft_export(char **args)
{
	int	is_error;
	int	i;

	is_error = 0;
	i = 1;
	if (!args[i])
		export_list();
	while (args[i])
	{
		if (ft_putenv(args[i]) == INVALID_NAME)
		{
			is_error = 1;
			g_status = EXIT_FAILURE;
			errno = E_VALID;
			ft_putstr_fd("minish: export: `", STDERR);
			ft_putstr_fd(args[i], STDERR);
			ft_putstr_fd("'", STDERR);
			ft_perror("");
		}
		i++;
	}
	if (!is_error)
		g_status = EXIT_SUCCESS;
	return (STAY_LOOP);
}
