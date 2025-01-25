/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:22:34 by plesukja          #+#    #+#             */
/*   Updated: 2024/12/31 13:46:06 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_count(char c, int *length)
{
	write(1, &c, 1);
	(*length)++;
}

void	ft_putstr_count(char *str, int *length)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		(*length) += write(1, "(null)", 6);
		return ;
	}
	while (str[i])
	{
		ft_putchar_count(str[i], length);
		i++;
	}
}

char	ft_printf_toupper(char c)
{
	if (c >= 'a' && c <= 'f')
		return (c - 32);
	return (c);
}

// char *ft_toupper(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] >= 'a' && str[i] <= 'f')
// 			str[i] -= 32;
// 		i++;
// 	}
// 	return (str);
// }

void	ft_putptr(size_t ptr, int *length)
{
	char	str[20];
	int		i;
	char	*base_chars;

	i = 0;
	base_chars = "0123456789abcdef";
	(*length) += write(1, "0x", 2);
	if (ptr == 0)
	{
		ft_putchar_count('0', length);
		return ;
	}
	while (ptr)
	{
		str[i] = base_chars[(ptr) % 16];
		ptr = ptr / 16;
		i++;
	}
	while (--i >= 0)
		(*length) += write(1, &str[i], 1);
}

void	ft_putnum(long long int nbr, int *length, int base, char d_i_x_or_X)
{
	char	str[20];
	int		i;
	char	*base_chars;

	i = 0;
	base_chars = "0123456789abcdef";
	if (nbr == 0)
		str[i++] = '0';
	if (nbr < 0)
	{
		nbr *= -1;
		(*length) += write(1, "-", 1);
	}
	while (nbr > 0)
	{
		if (d_i_x_or_X == 'x' || d_i_x_or_X == 'd' || d_i_x_or_X == 'i')
			str[i++] = base_chars[nbr % base];
		else if (d_i_x_or_X == 'X')
			str[i++] = ft_printf_toupper(base_chars[nbr % base]);
		nbr /= base;
	}
	while (--i >= 0)
		(*length) += write(1, &str[i], 1);
}
