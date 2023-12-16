/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anon </var/spool/mail/anon>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 00:00:00 by anon              #+#    #+#             */
/*   Updated: 2023/12/16 00:20:20 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
		len = ft_strlen(str);
	write(1, str, len);
	pa->len = len;
}
