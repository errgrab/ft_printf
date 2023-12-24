/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_flg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anon </var/spool/mail/anon>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:30:34 by anon              #+#    #+#             */
/*   Updated: 2023/12/16 20:28:55 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_eval_flg(t_pa *pa, char flg)
{
	if (!ft_strchr(pa->flg, flg))
	{
		if (pa->flg_cnt < FLAGS_LEN)
			pa->flg[pa->flg_cnt++] = flg;
	}
}