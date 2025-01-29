/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 09:47:19 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/18 16:54:55 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	printf("*************************************\n");
	printf("--ft_strncmp--\n");
	char	str1_ft[20];
	char	str2_ft[20];
	strcpy(str1_ft, "Hi");
	strcpy(str2_ft, "Hi");
	printf("%d\n", ft_strncmp(str1_ft, str2_ft, 10));
	printf("--strncmp--\n");
	char	str1_man[20];
	char	str2_man[20];
	strcpy(str1_man, "Hi");
	strcpy(str2_man, "Hi");
	printf("%d\n", strncmp(str1_man, str2_man, 10));
}
*/