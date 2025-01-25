/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:37:18 by plesukja          #+#    #+#             */
/*   Updated: 2024/04/20 20:24:25 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fmt_convert(const char form, va_list args, int *length)
{
	if (form == 'c')
		ft_putchar_count(va_arg(args, int), length);
	else if (form == 's')
		ft_putstr_count(va_arg(args, char *), length);
	else if (form == 'p')
		ft_putptr(va_arg(args, size_t), length);
	else if (form == 'd' || form == 'i')
		ft_putnum(va_arg(args, int), length, 10, 'd');
	else if (form == 'x')
		ft_putnum(va_arg(args, unsigned int), length, 16, 'x');
	else if (form == 'X')
		ft_putnum(va_arg(args, unsigned int), length, 16, 'X');
	else if (form == 'u')
		ft_putnum(va_arg(args, unsigned int), length, 10, 'd');
}

int	ft_printf(const char *fmt, ...)
{
	int		length;
	va_list	args;

	length = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if ((*fmt == '%') && *(fmt + 1) == '%')
		{
			ft_putchar_count('%', &length);
			fmt = fmt + 2;
		}
		else if ((*fmt == '%') && (*(fmt + 1) == 'c' || *(fmt + 1) == 's'
				|| *(fmt + 1) == 'p' || *(fmt + 1) == 'd' || *(fmt + 1) == 'i'
				|| *(fmt + 1) == 'u' || *(fmt + 1) == 'x' || *(fmt + 1) == 'X'))
		{
			fmt_convert(*(fmt + 1), args, &length);
			fmt += 2;
		}
		else
			ft_putchar_count(*fmt++, &length);
	}
	va_end(args);
	return (length);
}
