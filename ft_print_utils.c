/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:31:09 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/10/16 13:20:19 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchr(va_list arg)
{
	char	chr;

	chr = va_arg(arg, int);
	return (write(1, &chr, 1));
}

int	ft_printstr(va_list arg)
{
	int		len;
	char	*str;

	str = va_arg(arg, char *);
	if (!str)
		return (write(1, "(null)", 6));
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int	ft_printptr(va_list arg)
{
	int		len;
	size_t	ptr;

	ptr = va_arg(arg, size_t);
	if (!ptr)
		return (write(1, "(nil)", 5));
	len = write(1, "0x", 2);
	len += ft_print_sbase(ptr, HEX_LOWER);
	return (len);
}

int	ft_printdig(va_list arg)
{
	int	dig;

	dig = va_arg(arg, int);
	return (ft_print_base(dig, DECIMAL));
}

int	ft_printuns(va_list arg)
{
	unsigned int	uns;

	uns = va_arg(arg, unsigned int);
	return (ft_print_sbase(uns, DECIMAL));
}
