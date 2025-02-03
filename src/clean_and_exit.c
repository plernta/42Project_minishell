/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:29:54 by plesukja          #+#    #+#             */
/*   Updated: 2025/02/03 16:25:54 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*parser_error(char *message, t_token *token)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (message)
		ft_putstr_fd(message, STDERR_FILENO);
	else
		ft_putstr_fd("error\n", STDERR_FILENO);
	free_tree(token);
	token = NULL;
	return (NULL);
}

void	close_fd(t_shell *shell)
{
	if (shell->default_stdin != STDIN_FILENO)
		close(shell->default_stdin);
	if (shell->default_stdout != STDOUT_FILENO)
		close(shell->default_stdout);
	if (shell->in_fd != STDIN_FILENO)
		close(shell->in_fd);
	if (shell->out_fd != STDOUT_FILENO)
		close(shell->out_fd);
}

void	clean_and_exit(t_shell *shell)
{
	int	exit_status_temp;

	exit_status_temp = shell->exit_status;
	close_fd(shell);
	if (shell->env_arr)
		free_array(shell->env_arr);
	if (shell->env)
		free_env(&shell->env);
	if (shell->current_cmd)
	{
		free_tree(shell->current_cmd);
		shell->current_cmd = NULL;
	}
	free(shell);
	rl_clear_history();
	exit(exit_status_temp);
}

void	error_exit(char *message, t_shell *shell)
{
	if (!shell)
		exit(EXIT_FAILURE);
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	perror(message);
	if (errno)
		shell->exit_status = errno;
	else
		shell->exit_status = 1;
	clean_and_exit(shell);
}
