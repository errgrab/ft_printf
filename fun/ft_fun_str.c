/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anon </var/spool/mail/anon>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 00:00:00 by anon              #+#    #+#             */
/*   Updated: 2023/12/16 01:28:55 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>


void	ft_str(va_list args, t_pa *pa)
{
	int		len;
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		pa->len = write(1, "(null)", 6);
		return ;
	}
	len = ft_strlen(str);
	if (pa->prc)
		len = pa->prc;
	if (pa->wid > len)
	{
		pa->len = len;
		if (ft_strchr(pa->flg, '-'))
			write(1, str, pa->len);
		while (pa->wid > len)
			len += write(1, " ", 1);
		if (!ft_strchr(pa->flg, '-'))
			write(1, str, pa->len);
	}
	else
		write(1, str, len);
	pa->len = len;
}
