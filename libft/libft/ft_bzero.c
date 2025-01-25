/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:21:13 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/22 13:28:39 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*tmp_ptr;
	size_t	i;

	tmp_ptr = (char *)s;
	i = 0;
	while (i < n)
	{
		tmp_ptr[i] = '\0';
		i++;
	}
}
/*
int main(void)
{
	printf("*************************************\n");
	printf("--ft_bzero--\n");
	char    str_ft[20] = "";
	ft_bzero(str_ft, 2);
	printf("%s\n", str_ft + 2);
	printf("--bzero--\n");
	char    str_man[20] = "";
	bzero(str_man, 2);
	printf("%s\n", str_man + 2);
}
*/