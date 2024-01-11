/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaravlh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:58:29 by anon              #+#    #+#             */
/*   Updated: 2024/01/11 23:33:12 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put(int num, t_arg *a);
static int	ft_prc(int num, t_arg *a);
static int	ft_wid(int num, t_arg *a);

void	ft_dig(va_list args, t_arg *a)
{
	int		num;
	int		len;
	char	*is_neg;

	num = va_arg(args, int);
	len = 0;
	is_neg = ft_strchr(a->flg, '-');
	if (!is_neg)
		len += ft_wid(num, a);
	len += ft_put(num, a);
	if (is_neg)
		len += ft_wid(num, a);
	a->len = len;
}

static int	ft_put(int num, t_arg *a)
{
	int				len;
	unsigned int	n;

	len = 0;
	n = num;
	if (num < 0)
	{
		len += write(1, "-", 1);
		n = -num;
	}
	else if (ft_strchr(a->flg, '+'))
		len += write(1, "+", 1);
	else if (ft_strchr(a->flg, ' '))
		len += write(1, " ", 1);
	len += ft_prc(num, a);
	if (!(ft_strchr(a->flg, '.') && a->prc == 0 && num == 0))
		len += ft_based(n, DEC);
	return (len);
}

static int	ft_prc(int num, t_arg *a)
{
	int				len;
	int				num_len;
	int				sig_len;
	unsigned int	n;

	len = 0;
	sig_len = 0;
	n = num;
	if (num < 0)
	{
		n = -num;
		sig_len++;
	}
	else if (ft_strchr(a->flg, '+') || ft_strchr(a->flg, ' '))
		sig_len++;
	num_len = ft_nbrlen(n, 10);
	if (ft_strchr(a->flg, '.'))
		while (a->prc > num_len + len)
			len += write(1, "0", 1);
	else if (ft_strchr(a->flg, '0') && !ft_strchr(a->flg, '-'))
		while (a->wid > num_len + sig_len + len)
			len += write(1, "0", 1);
	return (len);
}

static int	ft_wid(int num, t_arg *a)
{
	int				num_len;
	int				len;
	unsigned int	n;

	len = 0;
	n = num;
	if (num < 0)
		n = -num;
	num_len = ft_nbrlen(n, 10);
	if (ft_strchr(a->flg, '.') && num_len < a->prc)
		num_len = a->prc;
	if ((num > 0 && (ft_strchr(a->flg, ' ') || ft_strchr(a->flg, '+')))
		|| num < 0)
		num_len++;
	if (a->prc == 0 && num == 0 && ft_strchr(a->flg, '.'))
		num_len = 0;
	if (!ft_strchr(a->flg, '0')
		|| ft_strchr(a->flg, '.') || ft_strchr(a->flg, '-'))
		while (a->wid > num_len + len)
			len += write(1, " ", 1);
	return (len);
}
