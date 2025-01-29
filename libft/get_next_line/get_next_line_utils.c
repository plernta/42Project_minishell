/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:50:56 by plesukja          #+#    #+#             */
/*   Updated: 2025/01/04 12:31:19 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_gnl_calloc(size_t size, size_t count)
{
	char	*tmp;
	size_t	i;

	if ((count > 0 && __SIZE_MAX__ / count < size) || size <= 0 || count <= 0)
		return (NULL);
	tmp = malloc(size * count);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		tmp[i] = '\0';
		i++;
	}
	return (tmp);
}

int	ft_gnl_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_gnl_strchr(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	if (*s == c)
		return ((char *)s);
	else
		return (NULL);
}
