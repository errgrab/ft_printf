/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:35:03 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/09 15:36:19 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put(char *str, t_arg *a);
static int	ft_wid(char *str, t_arg *a);

void	ft_str(va_list args, t_arg *a)
{
	char	*str;
	char	*is_neg;
	int		len;

	str = va_arg(args, char *);
	is_neg = ft_strchr(a->flg, '-');
	len = 0;
	if (!is_neg)
		len += ft_wid(str, a);
	len += ft_put(str, a);
	if (is_neg)
		len += ft_wid(str, a);
	a->len = len;
}

static int	ft_put(char *str, t_arg *a)
{
	int		len;

	if (!str)
	{
		if (ft_strchr(a->flg, '.') && a->prc < 6)
			return (0);
		return (write(1, "(null)", 6));
	}
	len = ft_strlen(str);
	if (ft_strchr(a->flg, '.') && a->prc < len)
		len = a->prc;
	return (write(1, str, len));
}

static int	ft_wid(char *str, t_arg *a)
{
	int	str_len;
	int	len;

	str_len = 0;
	len = 0;
	if (!str)
	{
		if (ft_strchr(a->flg, '.') && a->prc < 6)
			str_len = 0;
		else
			str_len = 6;
	}
	else
	{
		str_len = ft_strlen(str);
		if (ft_strchr(a->flg, '.') && a->prc < str_len)
			str_len = a->prc;
	}
	while (a->wid > str_len + len)
		len += write(1, " ", 1);
	return (len);
}
