/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:40:41 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/10/16 13:40:27 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list arg, char const format)
{
	t_fun	*convs_fun;

	convs_fun = (t_fun[]){
		ft_printchr, ft_printstr, ft_printptr, ft_printdig, ft_printdig,
		ft_printuns, ft_printhexl, ft_printhexu, ft_printdef
	};
	if (!ft_strchr(CONVS, format))
		return (write(1, &format, 1));
	return (convs_fun[ft_strchr(CONVS, format) - CONVS](arg));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			len += ft_format(args, format[++i]);
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
