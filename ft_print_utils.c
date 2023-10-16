/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:31:09 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/10/16 10:47:40 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchr(char chr)
{
	return (write(1, &chr, 1));
}

int	ft_printstr(char *str)
{
	int	len;

	if (!str)
		return (ft_print_str("(null)"));
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int	ft_printptr(size_t ptr)
{
	int	len;

	if (!ptr)
		return (write(1, "(nil)", 5));
	len = write(1, "0x", 2);
	len += ft_print_sbase(ptr, HEX_LOWER);
	return (len);
}
