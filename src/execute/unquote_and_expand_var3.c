/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unquote_and_expand_var3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 01:03:37 by plesukja          #+#    #+#             */
/*   Updated: 2025/01/24 22:44:05 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*join;

	join = ft_strjoin(s1, s2);
	if (!join)
		return (NULL);
	free(s1);
	free(s2);
	return (join);
}

bool	is_empty(char **s)
{
	if ((*s && ((*s)[0] == '\'' || (*s)[0] == '"')) && (*s)[1] == '\0')
	{
		*s += 1;
		return (true);
	}
	return (false);
}
