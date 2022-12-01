/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:41:56 by cgross            #+#    #+#             */
/*   Updated: 2022/11/29 15:25:26 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BASE16 "0123456789abcdef"
# define CAP_BASE16 "0123456789ABCDEF"

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putnbr(int nb);
int		ft_putunbr(unsigned int nb);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_puthexa(unsigned int x, char *base);
int		ft_putptr(unsigned long x, char *base, int start);

#endif
