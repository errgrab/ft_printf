/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_uns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anon </var/spool/mail/anon>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 00:00:05 by anon              #+#    #+#             */
/*   Updated: 2023/12/16 21:25:20 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_uns(va_list args, t_pa *pa)
{
	unsigned int	num;
	int				len;

	num = va_arg(args, unsigned int);
	len = ft_based(num, UDEC);
	pa->len = len;
}
