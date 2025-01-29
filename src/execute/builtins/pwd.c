/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:37:00 by plesukja          #+#    #+#             */
/*   Updated: 2024/12/27 16:40:08 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	run_builtin_pwd(t_shell *shell)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		perror("pwd");
		shell->exit_status = EXIT_FAILURE;
	}
	else
	{
		ft_putendl_fd(cwd, STDOUT_FILENO);
		free(cwd);
		shell->exit_status = EXIT_SUCCESS;
	}
}
