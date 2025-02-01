/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_process_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:35:44 by plesukja          #+#    #+#             */
/*   Updated: 2025/02/01 16:26:58 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static char	*init_prompt(t_shell *shell)
// {
// 	char	*pwd;
// 	char	*final_prompt;
// 	char	*old_prompt;

// 	pwd = ft_getenv(shell->env, "PWD");
// 	old_prompt = ft_strjoin("minishell@:", pwd);
// 	free(pwd);
// 	final_prompt = ft_strjoin(old_prompt, "$ ");
// 	free(old_prompt);
// 	return (final_prompt);
// }

int	get_input(char **line, t_shell *shell)
{
	char	*prompt;

	(void)shell;
	g_signal = 0;
	prompt = "minishell$ ";
	*line = readline(prompt);
	if (!*line)
	{
		write(STDOUT_FILENO, "exit\n", 5);
		return (-1);
	}
	if (*line && **line)
		add_history(*line);
	return (0);
}

void	process_input(t_shell *shell, char *input)
{
	if (!build_tree(shell, input))
		return ;
	run_signals(2, shell);
	run_input(shell->current_cmd, shell);
	run_signals(1, shell);
}

bool	build_tree(t_shell *shell, char *input)
{
	shell->current_cmd = process_token(input);
	if (!shell->current_cmd)
	{
		shell->exit_status = 2;
		free(input);
		return (false);
	}
	else if (shell->current_cmd->type == COMMAND \
		&& !((t_cmd *)(shell->current_cmd))->av[0])
	{
		free_tree(shell->current_cmd);
		free(input);
		return (false);
	}
	if (shell->current_cmd->type == PIPE)
		shell->has_pipe = 1;
	shell->default_stdin = dup(STDIN_FILENO);
	shell->default_stdout = dup(STDOUT_FILENO);
	return (true);
}
