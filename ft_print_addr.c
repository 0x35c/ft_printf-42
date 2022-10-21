/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_addr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:46:13 by ulayus            #+#    #+#             */
/*   Updated: 2022/10/20 14:50:02 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
