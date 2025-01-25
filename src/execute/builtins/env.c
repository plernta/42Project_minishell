/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:30:30 by plesukja          #+#    #+#             */
/*   Updated: 2024/12/27 16:37:04 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	run_builtin_env(t_shell *shell, t_env *env)
{
	t_env	*curr;

	curr = env;
	while (curr)
	{
		if (curr->value)
			printf("%s=%s\n", curr->key, curr->value);
		curr = curr->next;
	}
	shell->exit_status = EXIT_SUCCESS;
}
