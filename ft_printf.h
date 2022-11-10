/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:41:56 by cgross            #+#    #+#             */
/*   Updated: 2022/11/08 17:36:16 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct	s_struct
{
	int	len;
	int	width;
}					t_struct;

char	*ft_strchr(const char *format);
int		ft_strlen(const char *format);

#endif
