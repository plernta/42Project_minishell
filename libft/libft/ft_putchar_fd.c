/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:49:48 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/02 20:49:09 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main(void)
{
	char	test_char = 'H';
	int		fd0 = 0;
	int		fd1 = 1;
	ft_putchar_fd(test_char, fd0);
	write(fd0, "\n", 1);
	ft_putchar_fd(test_char, fd1);
	write(1, "\n", 1);
	return (0);
}
*/