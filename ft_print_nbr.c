/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:08:35 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/10/14 19:30:41 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	int		len;
	char	*nb;

	nb = ft_itoa(n);
	if (!nb)
		return (0);
	len = ft_print_str(nb);
	free(nb);
	return (len);
}
