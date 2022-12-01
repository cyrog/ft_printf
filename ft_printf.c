/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:46:10 by cgross            #+#    #+#             */
/*   Updated: 2022/11/29 17:09:15 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	search_arg(va_list arg, const char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(arg, unsigned long), BASE16, 1));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(arg, unsigned int)));
	else if (c == 'x')
		return (ft_puthexa(va_arg(arg, unsigned int), BASE16));
	else if (c == 'X')
		return (ft_puthexa(va_arg(arg, unsigned int), CAP_BASE16));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (0);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;
	int		i;

	va_start(arg, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			len += search_arg(arg, format[++i]);
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
