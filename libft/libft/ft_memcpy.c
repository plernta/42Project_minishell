/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:51:36 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/18 17:04:56 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	printf("*************************************\n");
	printf("--ft_memcpy--\n");
	char	dest_ft[50];
	char	src_ft[50];
	strcpy(dest_ft, "VeryGood");
	strcpy(src_ft, "Hong Bravo");
	ft_memcpy(dest_ft, src_ft, 4);
	printf("%s\n", dest_ft);
	printf("--memcpy--\n");
	char	dest_man[50];
	char	src_man[50];
	strcpy(dest_man, "VeryGood");
	strcpy(src_man, "Hong Bravo");
	memcpy(dest_man, src_man, 4);
	printf("%s\n", dest_man);
}
*/