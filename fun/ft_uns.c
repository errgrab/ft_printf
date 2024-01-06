/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 00:00:05 by anon              #+#    #+#             */
/*   Updated: 2024/01/06 14:47:28 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_uns(va_list args, t_arg *a)
{
	unsigned int	num;
	int				len;

	num = va_arg(args, unsigned int);
	len = ft_based(num, UDE);
	a->len = len;
}
