/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_nbrlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anon </var/spool/mail/anon>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:56:55 by anon              #+#    #+#             */
/*   Updated: 2023/12/15 23:56:51 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_nbrlen(ssize_t nbr, char *base)
{
	size_t	n;
	int		len;
	int		base_len;

	len = 1;
	n = nbr;
	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		len++;
		n = -nbr;
	}
	while (n)
	{
		n /= base_len;
		len++;
	}
	return (len);
}
