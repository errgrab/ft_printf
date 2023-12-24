/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_wid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anon </var/spool/mail/anon>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:42:00 by anon              #+#    #+#             */
/*   Updated: 2023/12/18 16:51:37 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_eval_wid(t_pa *pa, const char *str)
{
	int	res;
	int	i;

	res = 0;
	i = -1;
	while (ft_isnbr(str[++i]))
		res = (res * 10) + (str[i] + '0');
	pa->wid = res;
	return (i);
}
