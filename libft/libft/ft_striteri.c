/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:22:53 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/06 14:01:10 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// char	my_custom_function(unsigned  int  index, char c)
// {
// 	return (char)(c + index);
// }

// int	main(void)
// {
// 	printf("*************************************\n");
// 	printf("--ft_striteri--\n");
// }