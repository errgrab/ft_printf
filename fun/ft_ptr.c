/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:59:56 by anon              #+#    #+#             */
/*   Updated: 2024/01/09 18:32:48 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put(size_t ptr);
static int	ft_wid(size_t ptr, t_arg *a);

void	ft_ptr(va_list args, t_arg *a)
{
	size_t	ptr;
	char	*is_neg;
	int		len;

	ptr = va_arg(args, size_t);
	is_neg = ft_strchr(a->flg, '-');
	len = 0;
	if (!is_neg)
		len += ft_wid(ptr, a);
	len += ft_put(ptr);
	if (is_neg)
		len += ft_wid(ptr, a);
	a->len = len;
}

static int	ft_put(size_t ptr)
{
	int	len;

	if (!ptr)
		return (write(1, "(nil)", 5));
	len = write(1, "0x", 2);
	len += ft_based(ptr, LHX);
	return (len);
}

static int	ft_wid(size_t ptr, t_arg *a)
{
	int	ptr_len;
	int	len;

	ptr_len = 0;
	len = 0;
	if (!ptr)
		ptr_len = 5;
	else
		ptr_len = ft_nbrlen(ptr, 16) + 2;
	while (a->wid > ptr_len + len)
		len += write(1, " ", 1);
	return (len);
}
