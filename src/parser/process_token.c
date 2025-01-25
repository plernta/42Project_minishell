/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:51:34 by plesukja          #+#    #+#             */
/*   Updated: 2025/01/24 23:17:41 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*process_token(char *s)
{
	char	*end;
	t_token	*token;

	end = s + ft_strlen(s);
	token = parse_pipe(&s, end);
	if (!token)
		return (NULL);
	find_next_token(&s, end, "");
	if (s != end)
	{
		return (NULL);
	}
	null_terminate(token);
	return (token);
}

bool	find_next_token(char **ptr, char *end, char *charset)
{
	char	*cur;

	cur = *ptr;
	while ((cur < end) && ft_strchr(WHITESPACE, *cur))
		cur++;
	*ptr = cur;
	if (*cur && ft_strchr(charset, *cur))
		return (true);
	else
		return (false);
}
