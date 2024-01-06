/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anon </var/spool/mail/anon>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:56:55 by anon              #+#    #+#             */
/*   Updated: 2024/01/06 15:42:28 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(ssize_t nbr, int base_len)
{
	size_t	n;
	int		len;

	len = 1;
	n = nbr;
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
