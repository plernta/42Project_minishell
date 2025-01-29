/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:09:50 by plesukja          #+#    #+#             */
/*   Updated: 2025/01/24 22:40:45 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	unset_env_arr(t_env **env, char *var)
{
	t_env	*prev;
	t_env	*curr;

	prev = NULL;
	curr = *env;
	while (curr)
	{
		if (ft_strcmp(curr->key, var) == 0)
		{
			if (prev == NULL)
				*env = curr->next;
			else
				prev->next = curr->next;
			free(curr->key);
			free(curr->value);
		}
		prev = curr;
		curr = curr->next;
	}
}

void	run_builtin_unset(t_shell *shell, char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		unset_env_arr(&shell->env, args[i]);
		i++;
	}
	shell->env_arr = env_to_arr(shell->env, shell->env_arr);
	shell->exit_status = EXIT_SUCCESS;
}
