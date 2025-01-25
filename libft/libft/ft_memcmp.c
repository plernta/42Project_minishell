/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:25:34 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/18 16:59:34 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		else
			i++;
	}
	return (0);
}
/*
int	main(void)
{
	printf("*************************************\n");
	printf("--ft_memcmp--\n");
	char	str1_ft[20];
	char	str2_ft[20];
	strcpy(str1_ft, "Happy");
	strcpy(str2_ft, "Happy");
	printf("%d\n", ft_memcmp(str1_ft, str2_ft, 8));
	printf("--memcmp--\n");
	char	str1_man[20];
	char	str2_man[20];
	strcpy(str1_man, "Happy");
	strcpy(str2_man, "Happy");
	printf("%d\n", memcmp(str1_man, str2_man, 8));
}
*/