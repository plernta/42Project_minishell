/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:26:56 by plesukja          #+#    #+#             */
/*   Updated: 2025/01/24 23:00:24 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

void	free_env(t_env **env)
{
	t_env	*temp;

	if (!env)
		return ;
	while (*env)
	{
		temp = *env;
		*env = (*env)->next;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
	*env = NULL;
}

void	free_tree(t_token *token)
{
	t_redir	*redir;

	if (!token)
		return ;
	else if (token->type == REDIR)
	{
		redir = (t_redir *)token;
		if (redir->mode == 'h' && redir->temp_file)
		{
			free(redir->temp_file);
			redir->temp_file = NULL;
		}
		free_tree(redir->prior_token);
		free(redir);
	}
	else if (token->type == PIPE)
	{
		free_tree(((t_pipe *)token)->left);
		free_tree(((t_pipe *)token)->right);
		free((t_pipe *)token);
	}
}
