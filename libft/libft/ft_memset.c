/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:32:37 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/06 13:59:52 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	char	*tmp_ptr;
	size_t	i;

	tmp_ptr = (char *)dest;
	i = 0;
	while (i < n)
	{
		tmp_ptr[i] = c;
		i++;
	}
	dest = tmp_ptr;
	return (dest);
}
/*
int	main(void)
{
	{
		printf("*************************************\n");
		printf("--ft_memset--\n");
		char	str_ft[50];
		strcpy(str_ft, "Very Good");
		ft_memset(str_ft, '!', 5);
		printf("%s\n", str_ft);
		printf("--memset--\n");
		char	str_man[50];
		strcpy(str_man, "Very Good");
		memset(str_man, '!', 5);
		printf("%s\n", str_man);
	}
}
*/