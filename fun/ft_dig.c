/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaravlh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:58:29 by anon              #+#    #+#             */
/*   Updated: 2024/01/10 15:40:24 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put(int num, t_arg *a);
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
	int				num_len;
	int				zeros;
	unsigned int	n;

	len = 0;
	zeros = 0;
	n = num;
	if (num < 0)
	{
		len += write(1, "-", 1);
		n = -num;
	}
	num_len = ft_nbrlen(n, 10);
	if (ft_strchr(a->flg, '.'))
		while (a->prc > num_len + zeros)
			zeros += write(1, "0", 1);
	len += ft_based(n, DEC);
	return (len + zeros);
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
	if (num < 0)
		num_len++;
	while (a->wid > num_len + len)
		len += write(1, " ", 1);
	return (len);
}
