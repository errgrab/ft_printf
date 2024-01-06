/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_based.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:00:32 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/12/16 20:40:02 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_based(size_t n, char *base)
{
	int		len;
	size_t	base_len;

	len = 0;
	base_len = ft_strlen(&base[1]);
	if (base[0] == '-' && (ssize_t)n < 0)
	{
		n = (size_t)(-(ssize_t)n);
		len += write(1, "-", 1);
	}
	if (n >= (size_t)base_len)
		len += ft_based(n / base_len, base);
	len += write(1, &base[(n % base_len) + 1], 1);
	return (len);
}
