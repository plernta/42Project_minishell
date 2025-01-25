/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:53:03 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/08 16:23:03 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (!dest && !src)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	if ((s < d) && (d < s + n))
	{
		d = d + n - 1;
		s = s + n - 1;
		while (n--)
			*d-- = *s--;
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}
/*
int	main(void)
{
	{
		printf("*************************************\n");
		printf("--ft_memmove--\n");
		char	buffer_ft[50];
		strcpy(buffer_ft, "VeryGood");
		ft_memmove(buffer_ft + 2, buffer_ft + 4, 4);
		printf("%s\n", buffer_ft);
		printf("--memmove--\n");
		char	buffer_man[50];
		strcpy(buffer_man, "VeryGood");
		memmove(buffer_man + 2, buffer_man + 4, 4);
		printf("%s\n", buffer_man);
	}
}
*/