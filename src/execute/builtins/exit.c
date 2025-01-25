/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:17:53 by plesukja          #+#    #+#             */
/*   Updated: 2025/01/17 16:23:17 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static bool	ft_is_num_arg(char *str)
{
	int	i;

	if (str[0] == '-' || str[0] == '+')
	{
		if (!str[1])
			return (false);
	}
	i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}
/*
Common exit statuses:
0: Success.
1-125: Error codes. Custom error statuses.
126: Command found but not executable // directory
127: Command not found.
128+n: Termination due to a signal, n is sig_num (128 + 9 = 137 for SIGKILL).
*/

void	run_builtin_exit(t_shell *shell, char **args)
{
	if (!shell->has_pipe)
		ft_putendl_fd("exit", STDOUT_FILENO);
	if (!args[1])
		shell->exit_status = EXIT_SUCCESS;
	else if (args[1] && !ft_is_num_arg(args[1]))
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(args[1], STDERR_FILENO);
		ft_putendl_fd(": numeric argument required", STDERR_FILENO);
		shell->exit_status = 2;
	}
	else if (args[1] && args[2])
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putendl_fd("too many arguments", STDERR_FILENO);
		shell->exit_status = EXIT_FAILURE;
	}
	else
		shell->exit_status = ft_atoi(args[1]) % 256;
	free_array(args);
	clean_and_exit(shell);
}
