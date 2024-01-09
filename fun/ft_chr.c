/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:57:58 by anon              #+#    #+#             */
/*   Updated: 2024/01/09 19:15:10 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_chr(va_list args, t_arg *a)
{
	char	c;
	char	*is_neg;
	int		len;

	c = va_arg(args, int);
	is_neg = ft_strchr(a->flg, '-');
	len = 1;
	if (is_neg)
		write(1, &c, 1);
	while (a->wid > len)
		len += write(1, " ", 1);
	if (!is_neg)
		write(1, &c, 1);
	a->len = len;
}
