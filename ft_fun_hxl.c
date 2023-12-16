/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_hxl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anon </var/spool/mail/anon>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:59:31 by anon              #+#    #+#             */
/*   Updated: 2023/12/16 21:30:56 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hxl(va_list args, t_pa *pa)
{
	unsigned int	hex;
	int				len;

	hex = va_arg(args, unsigned int);
	len = ft_based(hex, LHEX);
	pa->len = len;
}
