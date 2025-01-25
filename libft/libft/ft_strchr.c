/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:29:24 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/19 00:05:39 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s != 0)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
	return (NULL);
}
/*
int	main(void)
{
	printf("*************************************\n");
	printf("--ft_strchr--\n");
	char	str_ft[50];
	strcpy(str_ft, "");
	printf("%s\n", ft_strchr(str_ft, '0'));
	printf("%s\n", ft_strchr(str_ft, 0));
	printf("--strchr--\n");
	char	str_man[50];
	strcpy(str_man, "");
	printf("%s\n", strchr(str_man, '0'));
	printf("%s\n", strchr(str_man, 0));
}
*/