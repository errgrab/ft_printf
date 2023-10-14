/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:52:35 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/10/14 20:03:59 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_print_unbr(n / 10);
		n %= 10;
	}
	len += ft_print_char(n + '0');
	return (len);
}
