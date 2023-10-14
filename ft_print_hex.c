/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:28:41 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/10/14 20:43:12 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, const char *base)
{
	size_t	base_len;
	int		len;

	base_len = ft_strlen(base);
	len = 0;
	if (n >= base_len)
	{
		len += ft_print_hex(n / base_len, base);
	}
	len += ft_print_char(base[n % base_len]);
	return (len);
}
