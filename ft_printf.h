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

# define base16 "0123456789abcdef"
# define BASE16 "0123456789ABCDEF"

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>


typedef struct	s_struct
{
	int				len;
	int				width;
	int				d;
	char			*s;
	char			c;
	unsigned long	p;
}					t_struct;

char	*ft_strchr(const char c, const char *format);
int		ft_strlen(const char *format);
int		ft_intlen(int nb);
int		ft_putnbr(int nb);
int		ft_putunbr(unsigned int nb);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_puthexa(unsigned int x, char *base);
int		ft_putptr(unsigned long x, char *base, int start);

#endif
