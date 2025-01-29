/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:50:56 by plesukja          #+#    #+#             */
/*   Updated: 2025/01/29 17:34:19 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_gnl_strjoin(const char *s1, const char *s2)
{
	char	*result;
	int		i;
	int		result_len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	result_len = ft_gnl_strlen((char *)s1) + ft_gnl_strlen((char *)s2);
	result = malloc (sizeof(char) * (result_len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}

char	*ft_gnl_strjoin_free(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_gnl_strjoin(s1, s2);
	free(s1);
	return (tmp);
}
