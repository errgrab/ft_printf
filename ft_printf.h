/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:12:09 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/10/16 10:50:27 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

/* Conversions and flags. */
# define CONVS "cspdiuxX%"
# define FLAGS "-0.# +"

/* Bases used */
# define DECIMAL   "0123456789"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

/* (^-^ ) */
int	ft_printf(const char *format, ...);

/* The BASE for everything */
int	ft_print_base(int n, const char *base);
int	ft_print_sbase(size_t n, const char *base);

/* Utils */
int	ft_printchr(char chr);
int	ft_printstr(char *str);
int	ft_printptr(size_t ptr);

#endif
