/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:31:16 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/22 13:19:20 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	to_trim(char const *set, char const c);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*result;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && to_trim(set, s1[start]))
		start++;
	while (end > start && to_trim(set, s1[end]))
		end--;
	result = malloc((end - start + 1) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (start <= end)
		result[i++] = s1[start++];
	result[i] = '\0';
	return (result);
}

static int	to_trim(char const	*set, char const c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	printf("*************************************\n");
	printf("--ft_strtrim--\n");
	printf("%s\n", ft_strtrim("-o-Hi there-jkh", "ojkh"));
}
*/