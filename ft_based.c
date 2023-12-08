/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_based.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:00:32 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/12/08 12:15:25 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_based(int fd, size_t n, const char *base)
{
	int		len;
	size_t	base_len;

	len = 0;
	base_len = 0;
	if (base[0] == '-' && (ssize_t)n < 0)
	{
		n = (size_t)(-(ssize_t)n);
		len += write(fd, "-", 1);
	}
	while ((&base[1])[base_len])
		base_len++;
	if (n >= base_len)
		len += ft_print_base(fd, n / base_len, base);
	len += write(fd, &base[(n % base_len) + 1], 1);
	return (len);
}
