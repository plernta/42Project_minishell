/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_terminate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:17:15 by plesukja          #+#    #+#             */
/*   Updated: 2025/01/24 23:29:15 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_token	*cmd_null_terminate(t_token *token)
{
	int		i;
	t_cmd	*cmd;

	i = 0;
	cmd = (t_cmd *)token;
	while (cmd->av[i])
	{
		*cmd->end_av[i] = 0;
		i++;
	}
	return ((t_token *)cmd);
}

static t_token	*redir_null_terminate(t_token *token)
{
	t_redir	*redir;

	redir = (t_redir *)token;
	null_terminate(redir->prior_token);
	*redir->end_file = 0;
	return ((t_token *)redir);
}

static t_token	*pipe_null_terminate(t_token *token)
{
	t_pipe	*pipe;

	pipe = (t_pipe *)token;
	null_terminate(pipe->left);
	null_terminate(pipe->right);
	return ((t_token *)pipe);
}

t_token	*null_terminate(t_token *token)
{
	if (!token)
		return (NULL);
	if (token->type == COMMAND)
		cmd_null_terminate(token);
	else if (token->type == REDIR)
		redir_null_terminate(token);
	else if (token->type == PIPE)
		pipe_null_terminate(token);
	return (token);
}
