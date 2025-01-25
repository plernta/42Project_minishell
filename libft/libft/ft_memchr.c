/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:07:08 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/18 15:24:16 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (str + i);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("*************************************\n");
	printf("--ft_memchr--\n");
	char	str_ft[50] = "";

	void *result_ft = ft_memchr(str_ft, 'o', 5);
	if (result_ft != NULL)
    	printf("Substring: %s\n", (char *)result_ft);
	else
    	printf("Not found\n");

	printf("--memchr--\n");
	char	str_man[50] = "";

	void *result_man = memchr(str_man, 'o', 5);
	if (result_man != NULL)
    	printf("Substring: %s\n", (char *)result_man);
	else
    	printf("Not found\n");

	return 0;
}
*/