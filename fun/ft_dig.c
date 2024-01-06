/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaravlh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:58:29 by anon              #+#    #+#             */
/*   Updated: 2024/01/06 14:37:33 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dig(va_list args, t_arg *a)
{
	int	num;
	int	len;

	num = va_arg(args, int);
	len = ft_based(num, SDE);
	a->len = len;
}
