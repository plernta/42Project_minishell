/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:40:56 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/22 13:43:40 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || (*str == '+'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		result *= 10;
		result += *str - 48;
		str++;
	}
	result *= sign;
	return (result);
}
/*
int	main(void)
{
	printf("*************************************\n");
	printf("--ft_atoi--\n");
	printf("%d\n", ft_atoi((void *)0));
	printf("%d\n", ft_atoi(NULL));
	printf("--atoi--\n");
	printf("%d\n", atoi((void *)0));
	printf("%d\n", atoi(NULL));
}
*/