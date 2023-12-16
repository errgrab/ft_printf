/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anon </var/spool/mail/anon>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:59:56 by anon              #+#    #+#             */
/*   Updated: 2023/12/16 20:29:50 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ptr(va_list args, t_pa *pa)
{
	int		len;
	size_t	ptr;

	ptr = va_arg(args, size_t);
	if (!ptr)
	{
		pa->len = write(1, "(nil)", 5);
		return ;
	}
	len = write(1, "0x", 2);
	len += ft_based(ptr, LHEX);
	pa->len = len;
}
