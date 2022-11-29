/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:46:10 by cgross            #+#    #+#             */
/*   Updated: 2022/11/29 17:02:52 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	search_arg(va_list arg, const char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(arg, char*)));
	else if (c == 'd')
		return (ft_putnbr(va_arg(arg, int)));
	else
		return (0);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	va_start(arg, format);
	int len;
	int	i;
	
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
	printf("len:		%d\n", len);
	return (len);
}

int	main(void)
{
	char *test = "test";
	char t = '\n';

	ft_printf("test\n"); 
	ft_printf("d	:	test%d\n", 1243); 
	ft_printf("s	:	test%s\n", test); 
	ft_printf("c	:	test%c\n", t); 
	ft_printf("test\n");
	return (0);
}
