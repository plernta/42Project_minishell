/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:41:30 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/22 13:18:38 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*result;

	i = 0;
	len = ft_strlen(s);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
char	my_custom_function(unsigned  int  index, char c)
{
	return (char)(c + index);
}

int	main(void)
{
	printf("*************************************\n");
	printf("--ft_strmapi--\n");
	printf ("%s\n", ft_strmapi("", my_custom_function));
}
*/