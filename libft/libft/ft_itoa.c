/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:57:29 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/07 11:22:38 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_digit(int n);

char	*ft_itoa(int nbr)
{
	long	num;
	int		i;
	char	*result;

	num = nbr;
	i = ft_num_digit (nbr);
	result = malloc((i + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[i] = '\0';
	i--;
	if (num == 0)
		result[0] = '0';
	if (num < 0)
	{
		result[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		result[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	return (result);
}

static int	ft_num_digit(int n)
{
	int	num_digit;

	num_digit = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
		num_digit++;
	while (n != 0)
	{
		n /= 10;
		num_digit++;
	}
	return (num_digit);
}

/*
int	main(void)
{
	printf("*************************************\n");
	printf("--ft_itoa--\n");
	printf("%s\n", ft_itoa(-1234));
	printf("%s\n", ft_itoa(+-1234));
	printf("%s\n", ft_itoa(-+1234));
	printf("%s\n", ft_itoa(-0));
}
*/