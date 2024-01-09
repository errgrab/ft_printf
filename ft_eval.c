/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anon <ecarvalh@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:12:08 by anon              #+#    #+#             */
/*   Updated: 2024/01/09 19:24:18 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Prototypes */
static void		ft_eval_put(t_arg *a, va_list args);
static int		ft_eval_flg(t_arg *a, const char *str);
static int		ft_eval_wid(t_arg *a, const char *str);
static int		ft_eval_prc(t_arg *a, const char *str);

/* The evaluation of this follow this syntax rule from the man page:
 * %{flg}[wid][.prc]cnv
 *
 * It may have some problems, but we keep trying to do our best! */
int	ft_eval(va_list args, const char *fmt, int *j)
{
	t_arg	a;
	int		i;

	i = 1;
	a = (t_arg){0};
	i += ft_eval_flg(&a, &fmt[i + *j]);
	i += ft_eval_wid(&a, &fmt[i + *j]);
	i += ft_eval_prc(&a, &fmt[i + *j]);
	if (ft_strchr(CNV, fmt[i + *j]))
	{
		*j += i;
		a.cnv = fmt[*j];
		ft_eval_put(&a, args);
	}
	if (!a.cnv)
		a.len = write(1, "%", 1);
	return (a.len);
}

static int	ft_eval_flg(t_arg *a, const char *str)
{
	int	i;

	i = 0;
	if (a->flp < FLL)
	{
		while (ft_strchr(FLG, str[i]))
		{
			if (!ft_strchr(a->flg, str[i]))
				a->flg[a->flp++] = str[i];
			i++;
		}
	}
	return (i);
}

/* The difference between the two eval is the starting evaluation point, and
 * the precision starts with the '.' flag. The two functions converts the
 * number in the argument of the conversion to a value and saves it's value
 * in a variable, that can be accesible in the "put" functions. */
static int	ft_eval_wid(t_arg *a, const char *str)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (ft_isnbr(str[++i]))
		res = (res * 10) + (str[i] - '0');
	a->wid = res;
	return (i);
}

static int	ft_eval_prc(t_arg *a, const char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (str[i] == '.')
	{
		while (ft_isnbr(str[++i]))
			res = (res * 10) + (str[i] - '0');
		a->flg[a->flp++] = '.';
	}
	a->prc = res;
	return (i);
}

/* This is to avoid the long (if else, elseif), it is an array of function
 * pointers that points at the same order of the conversions int the constant
 * CNV ("cspdiuxX%"), every character is a function, when the function is
 * executed it will execute a different function that will set some variables
 * and print the conversion in the screen. */
static void	ft_eval_put(t_arg *a, va_list args)
{
	void	(**f)(va_list, t_arg *);

	f = (void (*[])(va_list, t_arg *)){
		ft_chr, ft_str, ft_ptr, ft_dig, ft_dig, ft_uns, ft_hxl, ft_hxu, ft_def
	};
	f[ft_strchr(CNV, a->cnv) - CNV](args, a);
}
