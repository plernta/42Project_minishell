/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:06:31 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/15 23:25:17 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*tmp_str;

	if (count > 0 && SIZE_MAX / count < size)
		return (NULL);
	tmp_str = malloc(count * size);
	if (!tmp_str)
		return (NULL);
	return (ft_memset(tmp_str, 0, count * size));
}

/*
int	main(void)
{
	printf("*************************************\n");
	printf("--ft_calloc--\n");
	int	*tmp_calloc_ft;
	tmp_calloc_ft = ft_calloc(6, sizeof(int));
	if (!tmp_calloc_ft)
		return(1);
	printf("Calloc an array of 6 int\n");
	for (int i = 0; i < 6; i++)
		printf("%d ", tmp_calloc_ft[i]);
	printf("\n");
	free(tmp_calloc_ft);

	printf("--ft_calloc--\n");
	int	*tmp_calloc_man;
	tmp_calloc_man = calloc(6, sizeof(int));
	if (!tmp_calloc_man)
		return(1);
	printf("Calloc an array of 6 int\n");
	for (int i = 0; i < 6; i++)
		printf("%d ", tmp_calloc_man[i]);
	printf("\n");
	free(tmp_calloc_man);
}
*/