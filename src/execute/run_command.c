/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:46:41 by plesukja          #+#    #+#             */
/*   Updated: 2025/01/24 23:57:40 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	**parse_arguments(char **args, t_shell *shell)
{
	char	**new_args;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_args = ft_calloc(array_len(args) + 1, sizeof(char *));
	while (args[i])
	{
		tmp = unquote_and_expand_var(args[i], shell);
		if (tmp[0])
			new_args[j++] = tmp;
		else
			free(tmp);
		i++;
	}
	return (new_args);
}

void	run_command(t_cmd *cmd, t_shell *shell)
{
	char	**new_args;

	if (!cmd->av[0])
		return ;
	new_args = parse_arguments(cmd->av, shell);
	if (!new_args)
		error_exit("parse arguments failed", shell);
	if (is_builtin_cmd(new_args[0]))
		run_builtin_cmd(shell, new_args);
	else
	{
		if (shell->has_pipe)
			execute(new_args, shell);
		else
			fork_and_execute(new_args, shell);
	}
	free_array(new_args);
}

void	check_args_before_execute(char **args, t_shell *shell)
{
	if (!args || !args[0])
	{
		shell->exit_status = 0;
		free_array(args);
		clean_and_exit(shell);
	}
}

void	fork_and_execute(char **new_args, t_shell *shell)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		error_exit("fork failed", shell);
	else if (pid == 0)
		execute(new_args, shell);
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			shell->exit_status = WEXITSTATUS(status);
	}
}
