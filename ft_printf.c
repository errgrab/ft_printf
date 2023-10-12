/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:23:37 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/10/12 16:40:34 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	argp;
	int		i;
	
	i = 0;
	va_start(argp, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				ft_putchar(va_arg(argp, int));
			else if (format[i] == 's')
				ft_putstr(va_arg(argp, char *));
			else if (format[i] == 'p')
				ft_putptr(va_arg(argp, void *));
			else if (format[i] == 'd' || format[i] == 'i')
				ft_putnbr(va_arg(argp, int));
			else if (format[i] == 'u')
				ft_putunbr(va_arg(argp, int));
			else if (format[i] == 'x')
				ft_puthex(va_arg(argp, int));
			else if (format[i] == 'X')
			else if (format[i] == '%')
				ft_puthex(va_arg(argp, int));
				ft_putchar('%');
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	return (i);
}