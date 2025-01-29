/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:21:52 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/06 16:11:29 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

/*
int	main(void)
{
	printf("*************************************\n");
	printf("--ft_tolower--\n");
	printf("%d\n", ft_tolower(65));
	printf("--tolower--\n");
	printf("%d\n", tolower(65));
}
*/