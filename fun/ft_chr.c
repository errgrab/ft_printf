/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:57:58 by anon              #+#    #+#             */
/*   Updated: 2024/01/06 14:47:42 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_chr(va_list args, t_arg *a)
{
	int		len;
	char	c;

	c = va_arg(args, int);
	len = 1;
	if (a->wid > len)
	{
		if (ft_strchr(a->flg, '-'))
			write(1, &c, 1);
		while (a->wid > len)
			len += write(1, " ", 1);
		if (!ft_strchr(a->flg, '-'))
			write(1, &c, 1);
	}
	else
		write(1, &c, 1);
	a->len = len;
}
