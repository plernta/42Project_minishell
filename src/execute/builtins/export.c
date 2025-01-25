/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:59:12 by plesukja          #+#    #+#             */
/*   Updated: 2025/01/24 22:43:26 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static bool	is_valid_key(char *var)
{
	int	i;

	i = 0;
	if (!ft_isalpha(var[i]) && var[i] != '_')
		return (false);
	i++;
	while (var[i] && var[i] != '=')
	{
		if (!ft_isalnum(var[i]) && var[i] != '_')
			return (false);
		i++;
	}
	return (true);
}

void	run_builtin_export(t_shell *shell, char **args)
{
	int	i;

	i = 1;
	shell->exit_status = 0;
	if (!args[1])
		print_sorted_env(&shell->env);
	else
	{
		while (args[i])
		{
			if (!is_valid_key(args[i]))
			{
				ft_putstr_fd("minishell: export: ", STDERR_FILENO);
				ft_putstr_fd(args[i], STDERR_FILENO);
				ft_putendl_fd(": not a valid identifier", STDERR_FILENO);
				shell->exit_status = 1;
			}
			else
				add_or_update_env_var(&shell->env, args[i]);
			i++;
		}
		shell->env_arr = env_to_arr(shell->env, shell->env_arr);
	}
}
