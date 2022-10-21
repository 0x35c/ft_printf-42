/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:43:49 by ulayus            #+#    #+#             */
/*   Updated: 2022/10/18 19:14:57 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar_v(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_v(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		len += ft_putchar_v(*s);
		s++;
	}
	return (len);
}

int	ft_putnbase(long long nb, char *base, int reset)
{
	int			size;
	static int	count;

	if (reset)
		count = 0;
	size = ft_strlen(base);
	if (nb < 0)
	{
		count += ft_putchar_v('-');
		nb *= -1;
	}
	if (nb < (long long) size)
		count += ft_putchar_v(base[nb % size]);
	else
	{
		ft_putnbase((nb / size), base, 0);
		ft_putnbase((nb % size), base, 0);
	}
	return (count);
}

static int	ft_put_addr(unsigned long addr, char *base, int reset)
{
	unsigned long	size;
	static int		count_addr;

	if (reset)
		count_addr = 0;
	size = 16;
	if (addr < size)
		count_addr += ft_putchar_v(base[addr % size]);
	else
	{
		ft_put_addr((addr / size), base, 0);
		ft_put_addr((addr % size), base, 0);
	}
	return (count_addr);
}

int	ft_print_addr(unsigned long addr)
{
	int	len;

	len = 0;
	if (!addr)
	{
		len = ft_putstr_v("(nil)");
		return (len);
	}
	len = ft_putstr_v("0x");
	len += ft_put_addr(addr, BASE_HEX_LW, 1);
	return (len);
}
