/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:12:09 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/07 13:39:19 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

/* Conversions */
# define CNV "cspdiuxX%"
# define FLG "-0# +"

/* Bases */
# define SDE "-0123456789"
# define UDE " 0123456789"
# define LHX " 0123456789abcdef"
# define UHX " 0123456789ABCDEF"

/* Types */
typedef struct s_arg	t_arg;
struct s_arg
{
	char	*cnv;
	char	*flg;
	int		wid;
	int		prc;
	int		len;
};

/* <'-' > */
int		ft_printf(const char *format, ...);

/* Lib */
int		ft_based(size_t n, char *base); /* BASED */
char	*ft_strchr(char *str, int c);
int		ft_isnbr(int c);
int		ft_strlen(char *str);

/* Eval */
int		ft_eval(va_list args, const char *fmt, int *j);

/* ConvFun */
void	ft_chr(va_list args, t_arg *a); /* char        */
void	ft_str(va_list args, t_arg *a); /* string      */
void	ft_ptr(va_list args, t_arg *a); /* pointer     */
void	ft_dig(va_list args, t_arg *a); /* digit       */
void	ft_uns(va_list args, t_arg *a); /* unsigned    */
void	ft_hxl(va_list args, t_arg *a); /* hex lower   */
void	ft_hxu(va_list args, t_arg *a); /* hex upper   */
void	ft_def(va_list args, t_arg *a); /* default (%) */

#endif
