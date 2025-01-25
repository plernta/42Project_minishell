/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:54:53 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/06 13:58:32 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	printf("*************************************\n");
	printf("--ft_isascii--\n");
	printf("%d\n", ft_isascii('A'));
	//printf("%d\n", ft_isascii('€'));
	printf("--isascii--\n");
	printf("%d\n", isascii('A'));
	//printf("%d\n", isascii('€'));
}
*/