/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:26:38 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/12/08 12:15:10 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_chr(va_list arg)
{
	char	chr;

	chr = va_arg(arg, int);
	return (write(1, &chr, 1));
}

int	ft_str(va_list arg)
{
	int		len;
	char	*str;

	str = va_arg(arg, char *);
	len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}

int	ft_ptr(va_list arg)
{
	int		len;
	size_t	ptr;

	ptr = va_arg(arg, size_t);
	if (!ptr)
		return (write(1, "(nil)", 5));
	len = write(1, "0x", 2);
	len += ft_print_base(1, ptr, HEX_LOWER);
	return (len);
}
