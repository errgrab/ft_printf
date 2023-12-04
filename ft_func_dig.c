/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_funs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:31:09 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/11/03 15:25:48 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printdig(va_list arg)
{
	int	dig;

	dig = va_arg(arg, int);
	return (ft_print_base(1, (size_t)dig, SDECIMAL));
}

int	ft_printuns(va_list arg)
{
	unsigned int	uns;

	uns = va_arg(arg, unsigned int);
	return (ft_print_base(1, uns, DECIMAL));
}

int	ft_printhexl(va_list arg)
{
	unsigned int	hex;

	hex = va_arg(arg, unsigned int);
	return (ft_print_base(1, hex, HEX_LOWER));
}

int	ft_printhexu(va_list arg)
{
	unsigned int	hex;

	hex = va_arg(arg, unsigned int);
	return (ft_print_base(1, hex, HEX_UPPER));
}

int	ft_printdef(va_list arg)
{
	(void)arg;
	return (write(1, "%", 1));
}
