/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:40:41 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/11/13 13:15:19 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_formatted(va_list arg, char const format, char *flags)
{
	t_fun	*convs_fun;
	char	*convs;
	int		convs_ind;

	(void)flags;
	convs = CONVS;
	convs_ind = 0;
	convs_fun = (t_fun[]){
		ft_printchr, ft_printstr, ft_printptr, ft_printdig, ft_printdig,
		ft_printuns, ft_printhexl, ft_printhexu 
	};
	while (convs[convs_ind] && convs[convs_ind] != format)
		convs_ind++;
	if (!convs[convs_ind])
		return (write(1, &format, 1));
	return (convs_fun[convs_ind](arg));
}

static int	ft_format(va_list arg, char const *format)
{
	int	len;

	len = ft_print_formatted(arg, *format, "");
	return (len);
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
			len += ft_format(args, &format[++i]);
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
