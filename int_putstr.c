/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_putstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:22:09 by cgross            #+#    #+#             */
/*   Updated: 2022/11/29 15:44:35 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[len])
	{
		ft_putchar(s[len]);
		len++;
	}
	return (len);
}
