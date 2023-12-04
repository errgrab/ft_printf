/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:12:09 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/12/04 20:18:16 by ecarvalh         ###   ########.fr       */
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
# define CONVS_LEN 10

/* Bases used */
# define SDECIMAL  "-0123456789"
# define DECIMAL   " 0123456789"
# define HEX_LOWER " 0123456789abcdef"
# define HEX_UPPER " 0123456789ABCDEF"

/* (^-^ ) */
int	ft_printf(const char *format, ...);

/* The BASE for everything */
int	ft_based(int fd, size_t n, const char *base);

/* Utils */
int	ft_chr(va_list arg);
int	ft_str(va_list arg);
int	ft_ptr(va_list arg);
int	ft_dig(va_list arg);
int	ft_uns(va_list arg);
int	ft_hxl(va_list arg);
int	ft_hxu(va_list arg);
int	ft_prc(va_list arg);

/* FUN */
typedef int	(*t_fun)(va_list);
typedef struct s_flag {
	char	flags;
	int		width;
	int		precision;
}	t_flag;

#endif
