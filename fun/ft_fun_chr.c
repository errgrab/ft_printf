/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_chr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anon </var/spool/mail/anon>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:57:58 by anon              #+#    #+#             */
/*   Updated: 2023/12/16 01:28:57 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_chr(va_list args, t_pa *pa)
{
	int		len;
	char	c;

	c = va_arg(args, int);
	len = 1;
	if (pa->wid > len)
	{
		if (ft_strchr(pa->flg, '-'))
			write(1, &c, 1);
		while (pa->wid > len)
			len += write(1, " ", 1);
		if (!ft_strchr(pa->flg, '-'))
			write(1, &c, 1);
	}
	pa->len = len;
}
