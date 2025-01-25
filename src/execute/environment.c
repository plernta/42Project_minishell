/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:27:32 by plesukja          #+#    #+#             */
/*   Updated: 2025/01/24 22:46:48 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	add_node_to_arr(t_env *node, char **env_arr)
{
	int		i;
	char	*temp;

	i = 0;
	while (node)
	{
		if (!node->value)
			env_arr[i] = ft_strdup(node->key);
		else
		{
			temp = ft_strjoin(node->key, "=");
			if (!temp)
				return (0);
			env_arr[i] = ft_strjoin(temp, node->value);
			free(temp);
			if (!env_arr[i])
				return (0);
		}
		node = node->next;
		i++;
	}
	env_arr[i] = NULL;
	return (1);
}

char	**env_to_arr(t_env *env, char **old_envp)
{
	char	**env_arr;
	t_env	*node;
	int		count;

	if (!env)
		return (NULL);
	free_array (old_envp);
	count = 0;
	node = env;
	while (node)
	{
		count++;
		node = node->next;
	}
	env_arr = malloc(sizeof(char *) * (count + 1));
	if (!env_arr)
		return (NULL);
	if (!add_node_to_arr(env, env_arr))
	{
		free_array (env_arr);
		return (NULL);
	}
	return (env_arr);
}

char	*ft_getenv(t_env *env, char *key)
{
	t_env	*curr;

	if (!env || !key)
		return (NULL);
	curr = env;
	while (curr)
	{
		if (ft_strcmp(curr->key, key) == 0)
			return (ft_strndup(curr->value, -1));
		curr = curr->next;
	}
	return (NULL);
}
