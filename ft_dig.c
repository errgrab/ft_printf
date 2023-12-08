/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:31:09 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/12/08 12:15:19 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dig(va_list arg)
{
	int	dig;

	dig = va_arg(arg, int);
	return (ft_print_base(1, (size_t)dig, SDECIMAL));
}

int	ft_uns(va_list arg)
{
	unsigned int	uns;

	uns = va_arg(arg, unsigned int);
	return (ft_print_base(1, uns, DECIMAL));
}

int	ft_hxl(va_list arg)
{
	unsigned int	hex;

	hex = va_arg(arg, unsigned int);
	return (ft_print_base(1, hex, HEX_LOWER));
}

int	ft_hxu(va_list arg)
{
	unsigned int	hex;

	hex = va_arg(arg, unsigned int);
	return (ft_print_base(1, hex, HEX_UPPER));
}

int	ft_def(va_list arg)
{
	(void)arg;
	return (write(1, "%", 1));
}
