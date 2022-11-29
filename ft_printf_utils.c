/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
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

char	*ft_strchr(const char c, const char *s)
{
	if (!s)
		return ((char *)s);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

int		ft_strlen(const char *format)
{
	int	i;

	i = 0;
	while (format[i])
		i++;
	return i;
}

int		ft_intlen(int nb)
{
	int	i;
	int	number;
	int	neg;

	i = 1;
	neg = 1;
	if (nb < 0)
	{
		neg = neg * -1;
		number = -nb;
	}
	while (nb /= 10)
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}


int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (n < 0)
	{
		len += ft_putchar('-');
		n = -n;
	}
	else if (n > 9)
	{
		len += ft_putnbr(n / 10);
		len += ft_putchar(n % 10 + '0');
	}
	else
		len += ft_putchar(n + '0');
	return (len);
}
