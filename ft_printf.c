/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:40:41 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/12/04 20:30:01 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strchr(char *str, int c)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
	}
	return (NULL);
}

static int	ft_formatted(va_list arg, char format, t_flag *flag)
{
	t_fun	*fun;
	int		convs_ind;

	fun = (t_fun[]){
		ft_chr, ft_str, ft_ptr, ft_dig, ft_dig, ft_uns, ft_hxl, ft_hxu, ft_prc
	};
	if (!ft_strchr(CONVS, format))
		return (write(1, &format, 1));
	return (fun[ft_strchr(CONVS, format) - CONVS](arg));
}

static int	ft_eval(va_list arg, char const *format)
{
	int		len;
	int		i;
	t_flag	flag;

	flag = {0};
	i = -1;
	while (format[++i] && ft_strchr(FLAGS, format[i]))
	{
		while (++i)
	}

	len = ft_print_formatted(arg, *format, &flag);
	return (len + i);
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
			len += ft_eval(args, &format[++i]);
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
