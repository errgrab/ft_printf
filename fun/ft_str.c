/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:35:03 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/06 21:59:00 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str(va_list args, t_arg *a)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (!str)
	{
		a->len = write(1, "(null)", 6);
		return ;
	}
	len = ft_strlen(str);
	if (ft_strchr(a->flg, '.') && a->prc < len)
		len = a->prc;
	a->len = write(1, str, len);
}
