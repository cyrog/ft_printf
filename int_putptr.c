/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:22:09 by cgross            #+#    #+#             */
/*   Updated: 2022/11/29 15:44:35 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long x, char *base, int start)
{
	int				len;
	unsigned long	i;

	i = x;
	len = 0;
	if (x == 0)
		return (ft_putstr("0x0"));
	if (start)
		len += ft_putstr("0x");
	if (x >= 16)
	{
		len += ft_putptr(i / 16, base, 0);
		len += ft_putchar(base[i % 16]);
	}
	else
		len += ft_putchar(base[i]);
	return (len);
}
