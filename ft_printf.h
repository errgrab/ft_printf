/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:12:09 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/12/16 20:28:13 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

/* Conversions and flags. */
# define FLAGS "-0# +"
# define CONVS "cspdiuxX%"
# define FLAGS_LEN 5
# define CONVS_LEN 9

/* Bases used */
# define SDEC "-0123456789"
# define UDEC " 0123456789"
# define LHEX " 0123456789abcdef"
# define UHEX " 0123456789ABCDEF"

/* Types */
typedef struct s_pa /* print args   */
{
	char	f_chr;				/* format char  */
	char	flg[FLAGS_LEN + 1];	/* flags        */
	int		flg_cnt;			/* flags count  */
	int		wid;				/* width        */
	int		prc;				/* precision    */
	int		len;				/* lenght       */
}	t_pa;
typedef void	(*t_fun)(va_list, t_pa*);

/* (^-^ ) */
int		ft_printf(const char *format, ...);

/* BASED */
int		ft_based(size_t n, char *base);

/* Lib */
int		ft_nbrlen(ssize_t nbr, char *base);
int		ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
int		ft_putstr(char *str);

/* ConvFun */
void	ft_chr(va_list args, t_pa *pa); /* char        */
void	ft_str(va_list args, t_pa *pa); /* string      */
void	ft_ptr(va_list args, t_pa *pa); /* pointer     */
void	ft_dig(va_list args, t_pa *pa); /* digit       */
void	ft_uns(va_list args, t_pa *pa); /* unsigned    */
void	ft_hxl(va_list args, t_pa *pa); /* hex lower   */
void	ft_hxu(va_list args, t_pa *pa); /* hex upper   */
void	ft_def(va_list args, t_pa *pa); /* default (%) */

/* Eval */
int		ft_eval(va_list args, const char *fmt, int *j);
void	ft_eval_put(t_pa *pa, va_list args);
void	ft_eval_flg(t_pa *pa, char flg);
int		ft_eval_wid(t_pa *pa, const char *str);
int		ft_eval_prc(t_pa *pa, const char *str);

#endif
