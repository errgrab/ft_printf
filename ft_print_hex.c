/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:21:17 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/10/16 13:34:26 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexl(va_list arg)
{
	unsigned int	hex;

	hex = va_arg(arg, unsigned int);
	return (ft_print_sbase(hex, HEX_LOWER));
}

int	ft_printhexu(va_list arg)
{
	unsigned int	hex;

	hex = va_arg(arg, unsigned int);
	return (ft_print_sbase(hex, HEX_UPPER));
}

int	ft_printdef(va_list arg)
{
	(void)arg;
	return (write(1, "%", 1));
}
