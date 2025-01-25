/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:49:23 by plesukja          #+#    #+#             */
/*   Updated: 2025/01/24 22:44:55 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	run_input(t_token *token, t_shell *shell)
{
	if (!token)
		exit(EXIT_FAILURE);
	if (token->type == COMMAND)
		run_command((t_cmd *)token, shell);
	if (token->type == REDIR)
		run_redir((t_redir *)token, shell);
	if (token->type == PIPE)
		run_pipe((t_pipe *)token, shell);
}
