/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_no_var1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:17:57 by plesukja          #+#    #+#             */
/*   Updated: 2025/01/23 00:09:05 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static t_env	*duplicate_node(t_env *node)
{
	t_env	*new_node;

	if (!node)
		return (NULL);
	new_node = malloc (sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->key = ft_strdup(node->key);
	if (node->value)
		new_node->value = ft_strdup(node->value);
	else
		new_node->value = NULL;
	new_node->next = NULL;
	if (!new_node->key || (node->value && !new_node->value))
	{
		if (new_node->key)
			free (new_node->key);
		if (new_node->value)
			free (new_node->value);
		free (new_node);
		return (NULL);
	}
	return (new_node);
}

static bool	add_dup_node_in_new_env(t_env *dup_node,
t_env **new_env, t_env **tail)
{
	if (!dup_node)
		return (false);
	if (!*new_env)
		*new_env = dup_node;
	else
		(*tail)->next = dup_node;
	*tail = dup_node;
	return (true);
}

t_env	*clone_env(t_env **env)
{
	t_env	*cloned_env;
	t_env	*cur;
	t_env	*tail;
	t_env	*dup_node;

	if (!env || !*env)
		return (NULL);
	cloned_env = NULL;
	cur = *env;
	tail = NULL;
	while (cur)
	{
		dup_node = duplicate_node(cur);
		if (!dup_node)
		{
			free_env(&cloned_env);
			return (NULL);
		}
		add_dup_node_in_new_env(dup_node, &cloned_env, &tail);
		cur = cur->next;
	}
	return (cloned_env);
}

void	print_sorted_env(t_env **env)
{
	t_env	*cloned_env;
	t_env	*cur;

	cloned_env = clone_env(env);
	sort_env(&cloned_env);
	cur = cloned_env;
	while (cur)
	{
		if (!cur->value)
			printf("declare -x %s\n", cur->key);
		else
			printf("declare -x %s=\"%s\"\n", cur->key, cur->value);
		cur = cur->next;
	}
	free_env (&cloned_env);
}
