/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:35:13 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/20 15:18:16 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;

	result = NULL;
	while (*s)
	{
		if (*s == (char)c)
			result = (char *)s;
		s++;
	}
	if (*s == (char)c)
		result = (char *)s;
	return (result);
}
/*
int	main(void)
{
	printf("*************************************\n");
	printf("--ft_strchr--\n");
	char	str_ft[20];
	strcpy(str_ft, "");
	printf("%s\n", ft_strrchr(str_ft, 0));
	printf("%s\n", ft_strrchr(str_ft, '0'));
	printf("--strchr--\n");
	char	str_man[20];
	strcpy(str_man, "");
	printf("%s\n", strrchr(str_man, 0));
	printf("%s\n", strrchr(str_man,'0'));
}
*/