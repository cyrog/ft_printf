/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:48:49 by cgross            #+#    #+#             */
/*   Updated: 2022/11/29 15:14:40 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ... )
{
	int		len;
	int		i;
	va_list arg;

	va_start(arg, format);
	i = 0;
	len = 0;
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

int	search_arg(va_list arg, const char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else
		return (0);
}

int	main(void)
{
	ft_printf("%c", 'c');
}

