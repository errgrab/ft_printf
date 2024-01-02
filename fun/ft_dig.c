/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_dig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anon </var/spool/mail/anon>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:58:29 by anon              #+#    #+#             */
/*   Updated: 2023/12/16 21:09:16 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dig(va_list args, t_pa *pa)
{
	int	num;
	int	len;

	num = va_arg(args, int);
	len = ft_based(num, SDEC);
	pa->len = len;
}
