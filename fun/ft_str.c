/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:35:03 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/05 17:58:14 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_putstr(t_pa *pa, char *str)
{
	char	*neg_f;
	int		len;
	int		spaces;

	spaces = 0;
	neg_f = ft_strchr(pa->flg, '-');
	if (neg_f)
		write(1, str, len);
	while (pa->wid > len + spaces)
		spaces += write(1, " ", 1);
	if (!neg_f)
		write(1, str, len);
	return (len + spaces);
}

void	ft_str(va_list args, t_pa *pa)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	len = ft_strlen(str);
	if (ft_strchr(pa->flg, '.') && pa->prc < len)
		len = pa->prc;
	if (!str)
	{
		pa->len = write(1, "(null)", 6);
		return ;
	}
	write(1, str, len);
	pa->len = ft_put(pa, str);
}
