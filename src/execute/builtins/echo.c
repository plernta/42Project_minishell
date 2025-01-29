/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:24:01 by plesukja          #+#    #+#             */
/*   Updated: 2025/01/17 11:16:43 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	run_builtin_echo(t_shell *shell, char **args)
{
	int		i;
	bool	has_n_flag;

	i = 1;
	has_n_flag = false;
	while (args[i] && ft_strcmp(args[i], "-n") == 0)
	{
		has_n_flag = true;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], STDOUT_FILENO);
		if (args[i + 1])
			ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
	if (!has_n_flag)
		ft_putchar_fd('\n', STDOUT_FILENO);
	shell->exit_status = EXIT_SUCCESS;
}
