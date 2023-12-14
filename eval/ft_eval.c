/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anon <ecarvalh@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:12:08 by anon              #+#    #+#             */
/*   Updated: 2023/12/14 20:28:13 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/* The evaluation of this follow this syntax rule from the man page:
 * %[flags][width][.precision]conversion
 *
 * It may have some problems, but we keep trying to do our best! */

int	ft_eval(va_list args, char *str, int *j)
{
	t_pa	pa;
	int		i;

	i = 0;
	pa = (t_pa){0};
	while (ft_strchr(FLAGS, str[++i + *j]))
		ft_eval_flg(&pa, str[i + *j]);
	if (ft_strchr("0123456789", str[i + *j]))
		i += ft_eval_wid(&pa, &str[i + *j]);
	if (str[i + *j] == '.')
		i += ft_eval_prc(&pa, &str[i + *j]);
	if (ft_strchr(CONVS, str[i + *j]))
		pa.f_chr = str[i + *j];
	if (!pa.f_chr)
		pa.len = write(1, "%", 1);
	else
	{
		*j += i;
		ft_eval_put(args, &pa);
	}
	return (pa.len);
}
