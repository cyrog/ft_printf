/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:46:10 by cgross            #+#    #+#             */
/*   Updated: 2022/11/29 15:24:44 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*search_arg(va_list arg, const char *format, t_struct sc)
{
	if (*format == 'd')
	{
		sc.d = va_arg(arg, int);
		ft_putnbr(sc.d);
		sc.len = sc.len + ft_intlen(sc.d);
	}
	else if (*format == 's')
	{
		sc.s = va_arg(arg, char*);
		ft_putstr(sc.s);
		sc.len = sc.len + ft_strlen(sc.s);
	}
	else if (*format == 'c')
	{
		return (ft_putchar(va_arg(arg, int)));
	}
	else
		return (NULL);
	format++;
	return (format);
}

const char	*read_txt(t_struct sc, const char *format)
{
	char	*next;

	next = ft_strchr('%', format);
	if (next)
		sc.width = next - format;
	else
		sc.width = ft_strlen(format);
	write(1, format, sc.width);
	sc.len = sc.len + sc.width;
	while (*format && *format != '%')
		format++;
	return (format);
}


int	ft_printf(const char *format, ...)
{
	va_list		arg;
	va_start(arg, format);
	t_struct	sc;
	sc.len = 0;
	sc.width = 0;

	while (*format)
	{
		if (!format)
		{
			write(1, "(null)", 6);
			va_end(arg);
			return (sc.len);
		}
		else if (*format == '%')
			format = search_arg(arg, format + 1, sc);
		else
			format = read_txt(sc, format);
	}
	va_end(arg);
	return (sc.len);
}

int	main(void)
{
	char *test = "test";
	char *pointeri = "test";
	char t = '\n';

	ft_printf("test\n");
	ft_printf("test%d\n", 12434); 
	ft_printf("test%s\n", test); 
	ft_printf("test%c\n", t); 
	ft_printf("test\n");
	return (0);
}
