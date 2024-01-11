/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 00:00:05 by anon              #+#    #+#             */
/*   Updated: 2024/01/11 20:08:48 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put(unsigned int num, t_arg *a);
static int	ft_wid(unsigned int num, t_arg *a);

void	ft_uns(va_list args, t_arg *a)
{
	unsigned int	num;
	int				len;
	char			*is_neg;

	num = va_arg(args, unsigned int);
	len = 0;
	is_neg = ft_strchr(a->flg, '-');
	if (!is_neg)
		len += ft_wid(num, a);
	len += ft_put(num, a);
	if (is_neg)
		len += ft_wid(num, a);
	a->len = len;
}

static int	ft_put(unsigned int num, t_arg *a)
{
	int	len;
	int	num_len;
	int	zeros;

	len = 0;
	zeros = 0;
	num_len = ft_nbrlen(num, 10);
	if (ft_strchr(a->flg, '.'))
		while (a->prc > num_len + zeros)
			zeros += write(1, "0", 1);
	else if (ft_strchr(a->flg, '0') && !ft_strchr(a->flg, '-'))
		while (a->wid > num_len + zeros)
			zeros += write(1, "0", 1);
	if (!(ft_strchr(a->flg, '.') && a->prc == 0))
		len += ft_based(num, DEC);
	return (len + zeros);
}

static int	ft_wid(unsigned int num, t_arg *a)
{
	int	len;
	int	num_len;

	len = 0;
	num_len = ft_nbrlen(num, 10);
	if (ft_strchr(a->flg, '.') && num_len < a->prc)
		num_len = a->prc;
	if (ft_strchr(a->flg, '.') && num == 0 && a->prc == 0)
		num_len = 0;
	if (!ft_strchr(a->flg, '0')
		|| ft_strchr(a->flg, '-') || ft_strchr(a->flg, '.'))
		while (a->wid > num_len + len)
			len += write(1, " ", 1);
	return (len);
}
