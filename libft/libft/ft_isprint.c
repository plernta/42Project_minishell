/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:39:57 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/08 13:45:04 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
int	main(void)
{
	printf("*************************************\n");
	printf("--ft_isprint--\n");
	printf("%d\n", ft_isprint('a'));
	printf("%d\n", ft_isprint('\n'));
	printf("%d\n", ft_isprint(' '));
	printf("%d\n", ft_isprint(31));
	printf("--isprint--\n");
	printf("%d\n", isprint('a'));
	printf("%d\n", isprint('\n'));
	printf("%d\n", isprint(' '));
	printf("%d\n", isprint(31));
}
*/