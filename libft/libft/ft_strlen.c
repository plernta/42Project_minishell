/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:41:23 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/20 16:08:52 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	printf("*************************************\n");
	printf("--strlen--\n");
	printf("%lu\n", strlen("abc"));
	printf("%lu\n", strlen("hello"));
	printf("%lu\n", strlen(""));
	printf("%lu\n", strlen("abc "));
	printf("--ft_strlen--\n");
	printf("%d\n", ft_strlen("abc"));
	printf("%d\n", ft_strlen("hello"));
	printf("%d\n", ft_strlen(""));
	printf("%d\n", ft_strlen("abc "));
}
*/