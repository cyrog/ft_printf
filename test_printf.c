/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:44:27 by cgross            #+#    #+#             */
/*   Updated: 2022/11/24 14:08:37 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ... )
{
	va_list	arg;
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
		//else if (*format == '%')
		else
			*format = read_txt(sc, format);
	}
	va_end(arg);
	return (sc.len);
}
