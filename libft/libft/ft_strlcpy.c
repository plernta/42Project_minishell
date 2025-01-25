/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:53:35 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/22 13:16:19 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
int	main(void)
{
	printf("*************************************\n");
	printf("--strlcpy--\n");
	char	dst_man[20];
	char	src_man[5];
	strcpy(dst_man, "AB");
	strcpy(src_man, "");
	size_t result_man = strlcpy(dst_man, src_man, 2);
	printf("Content: %s\n", dst_man);
	printf("Length: %zu\n", result_man);
	printf("--ft_strlcpy--\n");
	char	dst_ft[20];
	char	src_ft[5];
	strcpy(dst_ft, "AB");
	strcpy(src_ft, "");
	size_t result_ft = ft_strlcpy(dst_ft, src_ft, 2);
	printf("Content: %s\n", dst_ft);
	printf("Length: %zu\n", result_ft);
}
*/