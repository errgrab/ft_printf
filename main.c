/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:13:17 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/11 23:39:34 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	i;
	int	len;
	int	(*print)(const char *, ...);

	i = 0;
	print = printf;
	print("printf:\n");
	while (i++ != 2)
	{
		len = print("%---105p%-%%--150.i" ,(void*)5854188174500153960lu,-1646567843);
		print("len: %d\n", len);
		if (i == 1)
		{
			print("ft_printf:\n");
			print = ft_printf;
		}
	}
	return (0);
}
