/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:14:14 by plesukja          #+#    #+#             */
/*   Updated: 2025/01/24 22:40:23 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

bool	is_builtin_cmd(char *arg)
{
	if (!arg)
		return (false);
	if (ft_strcmp(arg, "echo") == 0 || ft_strcmp(arg, "cd") == 0
		|| ft_strcmp(arg, "pwd") == 0 || ft_strcmp(arg, "export") == 0
		|| ft_strcmp(arg, "unset") == 0 || ft_strcmp(arg, "env") == 0
		|| ft_strcmp(arg, "exit") == 0)
		return (true);
	return (false);
}

void	run_builtin_cmd(t_shell *shell, char **arg)
{
	if (ft_strcmp(arg[0], "echo") == 0)
		run_builtin_echo(shell, arg);
	else if (ft_strcmp(arg[0], "cd") == 0)
		run_builtin_cd(shell, arg);
	else if (ft_strcmp(arg[0], "pwd") == 0)
		run_builtin_pwd(shell);
	else if (ft_strcmp(arg[0], "export") == 0)
		run_builtin_export(shell, arg);
	else if (ft_strcmp(arg[0], "unset") == 0)
		run_builtin_unset(shell, arg);
	else if (ft_strcmp(arg[0], "env") == 0)
		run_builtin_env(shell, shell->env);
	else if (ft_strcmp(arg[0], "exit") == 0)
		run_builtin_exit(shell, arg);
}
