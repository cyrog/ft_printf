/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:22:09 by cgross            #+#    #+#             */
/*   Updated: 2022/11/08 17:41:34 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s)
{
	if (!s)
		return ((char *)s);
	while (*s)
	{
		if (*s == '%')
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
