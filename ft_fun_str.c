/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anon </var/spool/mail/anon>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 00:00:00 by anon              #+#    #+#             */
/*   Updated: 2023/12/16 21:22:30 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_put(t_pa *pa, char *str)
{
	char	*neg_f;
	int		len;
	int		i;

	i = 0;
	neg_f = ft_strchr(pa->flg, '-');
	if (pa->prc)
		len = pa->prc;
	else
		len = ft_strlen(str);
	if (neg_f)
		write(1, str, len);
	while (pa->wid > len - i)
		i += write(1, " ", 1);
	if (!neg_f)
		write(1, str, len);
	return (len + i);
}

void	ft_str(va_list args, t_pa *pa)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		pa->len = write(1, "(null)", 6);
		return ;
	}
	pa->len = ft_put(pa, str);
}
