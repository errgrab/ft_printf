/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:55:27 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/10/15 13:31:16 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	test(int (*print)(const char *str, ...))
{
	char	a;

	a = 42;
	print("char: %c%c%c%c%c%c%c%c%c\n", "aWRs"[1], 'e', 0154, 0x63, 'o', 109,
		101, '~', 0);
	print("string: %s %s\n", &"this is a string"[4], NULL);
	print("pointer: %p %p %p\n", NULL, &a, 257);
	print("digit: %d %d %d %d\n", 42, 0x42, 0, -420129012);
}

int	main(int argc, char **argv)
{
	if (argc == 2 && ft_atoi(argv[1]) == 2)
	{
		printf("Yours:\n");
		test(ft_printf);
	}
	else if (argc == 2 && ft_atoi(argv[1]) == 3)
	{
		printf("Ours\n");
		test(printf);
		printf("Yours:\n");
		test(ft_printf);
	}
	else
	{
		printf("Ours:\n");
		test(printf);
	}
	return (0);
}
