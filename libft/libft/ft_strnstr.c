/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:08:15 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/20 15:02:59 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;
	char	*hay;

	i = 0;
	needle_len = ft_strlen(needle);
	hay = (char *)haystack;
	if (*needle == '\0' || haystack == needle)
		return (hay);
	if (len == 0 || needle_len == 0)
		return (NULL);
	while (i < len && hay[i] != '\0')
	{
		j = 0;
		while (hay[i + j] == needle[j] && i + j < len && \
		needle[j] != '\0' && hay[i + j])
			j++;
		if (j == needle_len)
			return (&hay[i]);
		i++;
	}
	return (NULL);
}

/*
int main(void)
{
	printf("*************************************\n");
	printf("--strnstr--\n");
	char	haystack_man[20];
	char	needle_man[20];
	strcpy(haystack_man, "");
	strcpy(needle_man, "E");
	printf("%s\n", strnstr(haystack_man, needle_man, 6));
	printf("--ft_strnstr--\n");
	char	haystack_ft[20];
	char	needle_ft[20];
	strcpy(haystack_ft, "");
	strcpy(needle_ft, "E");
	printf("%s\n", ft_strnstr(haystack_ft, needle_ft, 6));
}
*/