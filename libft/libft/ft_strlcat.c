/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:57:41 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/22 13:36:33 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	i = 0;
	dst_len = ft_strlen(dst);
	j = dst_len;
	while (src[i] && j < dstsize - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	if (dstsize < dst_len)
		return (src_len + dstsize);
	else
		return (dst_len + src_len);
}
/*
int	main(void)
{
	printf("*************************************\n");
	printf("--strlcat--\n");
	char	dst_man[20];
	char	src_man[5];
	strcpy(dst_man, "AB");
	strcpy(src_man, "");
	size_t result_man = strlcat(dst_man, src_man, 3);
	printf("Content: %s\n", dst_man);
	printf("Length: %zu\n", result_man);
	printf("--ft_strlcat--\n");
	char	dst_ft[20];
	char	src_ft[5];
	strcpy(dst_ft, "AB");
	strcpy(src_ft, "");
	size_t result_ft = ft_strlcat(dst_ft, src_ft, 3);
	printf("Content: %s\n", dst_ft);
	printf("Length: %zu\n", result_ft);
}
*/