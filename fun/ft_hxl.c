/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hxl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:59:31 by anon              #+#    #+#             */
/*   Updated: 2024/01/06 14:38:54 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hxl(va_list args, t_arg *a)
{
	unsigned int	hex;
	int				len;

	hex = va_arg(args, unsigned int);
	len = ft_based(hex, LHX);
	a->len = len;
}
