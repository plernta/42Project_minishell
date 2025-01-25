/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:59:04 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/06 14:03:29 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (c - 32);
	else
		return (c);
}
/*
int	main(void)
{
	printf("*************************************\n");
	printf("--ft_toupper--\n");
	printf("%d\n", ft_toupper(98));
	printf("--toupper--\n");
	printf("%d\n", toupper(98));
}
*/