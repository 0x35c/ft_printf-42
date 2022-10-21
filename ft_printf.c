/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:37:12 by ulayus            #+#    #+#             */
/*   Updated: 2022/10/20 14:50:34 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_dispatcher(const char *format, int i, va_list ap)
{
	int	count;

	count = 0;
	if (format[i] == 'c')
		count = ft_putchar_v((char) va_arg(ap, int));
	else if (format[i] == 's')
		count = ft_putstr_v(va_arg(ap, char *));
	else if (format[i] == 'd' || format[i] == 'i')
		count = ft_putnbase(va_arg(ap, int), BASE_10, 1);
	else if (format[i] == 'u')
		count = ft_putnbase(va_arg(ap, unsigned int), BASE_10, 1);
	else if (format[i] == 'x')
		count = ft_putnbase (va_arg(ap, unsigned int), BASE_HEX_LW, 1);
	else if (format[i] == 'X')
		count = ft_putnbase(va_arg(ap, unsigned int), BASE_HEX_UP, 1);
	else if (format[i] == 'p')
		count = ft_print_addr(va_arg(ap, unsigned long));
	else
	{
		count = ft_putchar_v('%');
		if (format[i] != '%')
			count += ft_putchar_v(format[i]);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_dispatcher(format, i, ap);
		}
		else
			count += ft_putchar_v(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
