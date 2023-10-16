/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:00:32 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/10/16 13:05:30 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_base(int n, const char *base)
{
	size_t			base_len;
	int				len;
	unsigned int	tmp;

	base_len = ft_strlen(base);
	len = 0;
	tmp = n;
	if (n < 0)
	{
		tmp = -n;
		len += write(1, "-", 1);
	}
	if (tmp >= base_len)
		len += ft_print_base(tmp / base_len, base);
	len += write(1, &base[tmp % base_len], 1);
	return (len);
}

int	ft_print_sbase(size_t n, const char *base)
{
	size_t	base_len;
	int		len;

	base_len = ft_strlen(base);
	len = 0;
	if (n >= base_len)
		len += ft_print_sbase(n / base_len, base);
	len += write(1, &base[n % base_len], 1);
	return (len);
}
