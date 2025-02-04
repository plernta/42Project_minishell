/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:37:54 by plesukja          #+#    #+#             */
/*   Updated: 2025/02/04 14:01:42 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_token	*create_cmd_token(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(*cmd));
	if (!cmd)
		return (NULL);
	ft_memset(cmd, 0, sizeof(*cmd));
	cmd->type = COMMAND;
	return ((t_token *)cmd);
}

static t_token	*parse_redirs(t_token *token, char **ptr, char *end)
{
	char	*file_start;
	char	*file_end;
	int		token_sign;
	int		file_token;

	while (find_next_token(ptr, end, "><"))
	{
		token_sign = go_get_token_sign(ptr, end, 0, 0);
		file_token = go_get_token_sign(ptr, end, &file_start, &file_end);
		if (!ft_strchr("a'\"", file_token) || !file_start || (!*file_start))
			return (parser_error("syntax error\n", token));
		token = create_redir_token(token, file_start, file_end, token_sign);
	}
	return (token);
}

static t_token	*parse_command_args(t_token *token, t_cmd *cmd, char **ptr,
char *end)
{
	char	*token_start;
	char	*token_end;
	int		ac;
	int		token_sign;

	ac = 0;
	while (!find_next_token(ptr, end, "|"))
	{
		token_sign = go_get_token_sign(ptr, end, &token_start, &token_end);
		if (token_sign == 0)
			break ;
		if (token_sign == -1 || !ft_strchr("a'\"", token_sign))
			return (parser_error("syntax error\n", token));
		cmd->av[ac] = token_start;
		cmd->end_av[ac] = token_end;
		ac++;
		token = parse_redirs(token, ptr, end);
	}
	cmd->av[ac] = 0;
	cmd->end_av[ac] = 0;
	return (token);
}

t_token	*parse_pipe(char **ptr, char *end)
{
	t_token	*left;
	t_token	*right;

	left = parse_token(ptr, NULL, end);
	if (!left)
		return (NULL);
	if (find_next_token(ptr, end, "|"))
	{
		if (left->type == COMMAND && !((t_cmd *)left)->av[0])
			return (parser_error("syntax error near unexpected token '|'\n", \
				left));
		go_get_token_sign(ptr, end, 0, 0);
		right = parse_pipe(ptr, end);
		if (!right || (right && right->type == COMMAND && \
			!((t_cmd *)right)->av[0]))
		{
			free_tree(right);
			if (right)
				return (parser_error("syntax error near unexpected token \
					'|'\n", left));
			return (NULL);
		}
		left = create_pipe_token(left, right);
	}
	return (left);
}

t_token	*parse_token(char **s, t_token *token, char *end)
{
	t_cmd	*cmd;

	token = create_cmd_token();
	if (!token)
		return (NULL);
	cmd = (t_cmd *)token;
	token = parse_redirs(token, s, end);
	if (!token)
		return (NULL);
	token = parse_command_args(token, cmd, s, end);
	if (!token)
		return (NULL);
	return (token);
}
