/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:07:03 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/19 00:37:38 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dst;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(src);
	dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	while (len != '0' && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
/*
int	main(void)
{
	printf("*************************************\n");
	printf("--ft_strdup--\n");
	printf("%s\n", ft_strdup(NULL));
	printf("--strdup--\n");
	printf("%s\n", strdup(NULL));
}
*/