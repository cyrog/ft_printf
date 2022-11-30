/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_puthexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:22:09 by cgross            #+#    #+#             */
/*   Updated: 2022/11/29 15:44:35 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int n, char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_puthexa(n / 16, base);
		len += ft_putchar(base[n % 16]);
	}
	else
		len += ft_putchar(base[n]);
	return (len);
}
