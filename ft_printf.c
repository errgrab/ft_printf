/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:40:41 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/10/15 13:15:36 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, const char format)
{
	if (format == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (format == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(args, size_t)));
	else if (format == 'd' || format == 'i')
		return (ft_print_base(va_arg(args, int), DECIMAL));
	else if (format == 'u')
		return (ft_print_ubase(va_arg(args, unsigned int), DECIMAL));
	else if (format == 'x')
		return (ft_print_ubase(va_arg(args, unsigned int), HEX_LOWER));
	else if (format == 'X')
		return (ft_print_ubase(va_arg(args, unsigned int), HEX_UPPER));
	else
		return (ft_print_char(format));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			len += ft_format(args, format[++i]);
		else
			len += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
