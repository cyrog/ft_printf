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

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		len += ft_putchar('-');
		n = -n;
	}
	if (n <= 9)
		len += ft_putchar(n + '0');
	else
	{
		len += ft_putnbr(n / 10);
		len += ft_putnbr(n % 10);
	}
	return (len);
}

int	ft_putunbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 9)
		len += ft_putchar(n + '0');
	else
	{
		len += ft_putunbr(n / 10);
		len += ft_putunbr(n % 10);
	}
	return (len);
}
