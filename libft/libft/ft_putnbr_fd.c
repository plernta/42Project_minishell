/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:51:02 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/04 18:51:46 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	result;

	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	if (num > 9)
	{
		ft_putnbr_fd((num / 10), fd);
		ft_putnbr_fd((num % 10), fd);
	}
	else
	{
		result = num + '0';
		write(fd, &result, 1);
	}
}
/*
int	main(void)
{
	ft_putnbr_fd(12345, 1);
	ft_putnbr_fd(-48, 1);
}
*/