/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_hxu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anon </var/spool/mail/anon>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:59:51 by anon              #+#    #+#             */
/*   Updated: 2023/12/16 21:30:57 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hxu(va_list args, t_pa *pa)
{
	unsigned int	hex;
	int				len;

	hex = va_arg(args, unsigned int);
	len = ft_based(hex, UHEX);
	pa->len = len;
}
