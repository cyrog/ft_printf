/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:44:27 by cgross            #+#    #+#             */
/*   Updated: 2022/11/07 21:06:11 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ... )
{
	va_list	arg;
	va_start(arg, format);
	t_struct sc;
	sc.len = 0;
	sc.width = 0;

	while (*format)
	{
		if (*format == '%')
			format = search_arg(arg, format + 1, &sc);
		else
			format = read_text(&sc, format);
		if (!format)
		{
			write(1, "(null)", 6);
			va_end(arg);
			return (sc.len);
		}
	}
	va_end(arg);
	return (sc.len);
}
