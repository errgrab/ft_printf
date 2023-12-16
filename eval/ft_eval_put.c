/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anon </var/spool/mail/anon>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:35:45 by anon              #+#    #+#             */
/*   Updated: 2023/12/15 19:56:42 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_eval_put(t_pa *pa, va_list args)
{
	t_fun	*fun;

	fun = (t_fun[]){
		ft_chr, ft_str, ft_ptr, ft_dig, ft_dig, ft_uns, ft_hxl, ft_hxu, ft_def
	};
	fun[ft_strchr(CONVS, pa->f_chr) - CONVS](args, pa);
}
