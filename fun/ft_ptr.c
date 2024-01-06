/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:59:56 by anon              #+#    #+#             */
/*   Updated: 2024/01/06 14:41:00 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ptr(va_list args, t_arg *a)
{
	int		len;
	size_t	ptr;

	ptr = va_arg(args, size_t);
	if (!ptr)
	{
		a->len = write(1, "(nil)", 5);
		return ;
	}
	len = write(1, "0x", 2);
	len += ft_based(ptr, LHX);
	a->len = len;
}
