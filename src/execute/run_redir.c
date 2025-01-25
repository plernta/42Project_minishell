/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:42:00 by plesukja          #+#    #+#             */
/*   Updated: 2025/01/24 22:45:53 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	redir_error(t_redir *redir, char *file, t_shell *shell)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (redir->mode == 'h')
		perror("here_doc");
	else
		perror(file);
	shell->exit_status = 1;
	if (shell->has_pipe)
	{
		free(file);
		clean_and_exit(shell);
	}
	close_fd(shell);
	return (-1);
}

static int	set_new_out_fd(t_redir *redir, char *file, t_shell *shell)
{
	int	out_fd;

	if (shell->out_fd >= 0 && shell->out_fd != STDOUT_FILENO)
		close(shell->out_fd);
	out_fd = -1;
	if (redir->mode == '>')
		out_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (redir->mode == '+')
		out_fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (out_fd < 0)
		return (redir_error(redir, file, shell));
	return (out_fd);
}

static int	set_new_in_fd(t_redir *redir, char *file, t_shell *shell)
{
	int	in_fd;

	if (shell->in_fd >= 0 && shell->in_fd != STDIN_FILENO)
		close(shell->in_fd);
	in_fd = open(file, O_RDONLY);
	if (redir->mode == 'h')
	{
		unlink (redir->temp_file);
		free (redir->temp_file);
		redir->temp_file = NULL;
	}
	if (in_fd < 0)
		return (redir_error(redir, file, shell));
	return (in_fd);
}

static void	apply_redir(t_shell *shell)
{
	if (shell->in_fd != STDIN_FILENO)
	{
		if (dup2(shell->in_fd, STDIN_FILENO) < 0)
			error_exit("dup2 failed redir in", shell);
		close(shell->in_fd);
	}
	if (shell->out_fd != STDOUT_FILENO)
	{
		if (dup2(shell->out_fd, STDOUT_FILENO) < 0)
			error_exit("dup2 failed redir out", shell);
		close(shell->out_fd);
	}
}

// char	*file_name for <, >, >> is the file_name
// char	*file_name for << (heredoc) is the delimiter
void	run_redir(t_redir *redir, t_shell *shell)
{
	char	*file_name;

	file_name = unquote_and_expand_var(redir->file, shell);
	if (!file_name)
	{
		redir_error(redir, file_name, shell);
		return ;
	}
	if (redir->mode == '>' || redir->mode == '+')
		shell->out_fd = set_new_out_fd(redir, file_name, shell);
	else if (redir->mode == '<' || redir->mode == 'h')
		shell->in_fd = set_new_in_fd(redir, file_name, shell);
	else if (redir->mode == 'h')
		shell->in_fd = set_new_in_fd(redir, redir->temp_file, shell);
	free (file_name);
	if (shell->in_fd < 0 || shell->out_fd < 0)
		return ;
	if (redir->prior_token->type == REDIR)
		run_redir((t_redir *)redir->prior_token, shell);
	else
	{
		apply_redir(shell);
		run_command((t_cmd *)redir->prior_token, shell);
	}
}
