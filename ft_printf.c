/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:46:10 by cgross            #+#    #+#             */
/*   Updated: 2022/11/08 17:39:28 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//char	*search_arg(va_list arg, const char *format, t_struct sc)
//

const char	*read_txt(t_struct sc, const char *format)
{
	char	*next;

	next = ft_strchr(format);
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
//		else if (*format == '%')
//			format = search_arg(arg, format, &sc);
		else
			format = read_txt(sc, format);
	}
	va_end(arg);
	return (sc.len);
}

int	main(void)
{
	ft_printf("test\n");
	return (0);
}
