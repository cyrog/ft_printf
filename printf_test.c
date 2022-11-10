/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:46:10 by cgross            #+#    #+#             */
/*   Updated: 2022/11/08 17:12:14 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*strchr_percent(const char *str)
{
	if (!str)
		return ((char*)str);
	while (*str)
	{
		if (*str == '%')
			return ((char*)str); 
		str++;
	}
	return (NULL);
}

//const char	*search_arg(va_list arg, t_struct sc, const char *format)


const char	*read_text(t_struct sc, const char *format)
{
	char	*next;

	next = strchr_percent(format);
	if (next)
		sc.width = next - format;
	else
		sc.width = ft_strlen(format);
	write(1, format, sc.width);
	sc.len = sc.width + sc.len;
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
//		if (*format == '%')
//			format = search_arg(arg, &sc, format);
		else
			format = read_text(sc, format);
	}
	va_end(arg);
	return (sc.len);
}

int	main(void)
{
	ft_printf("test\n");
	return (0);
}
