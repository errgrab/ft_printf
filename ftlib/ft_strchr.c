/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anon </var/spool/mail/anon>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:23:21 by anon              #+#    #+#             */
/*   Updated: 2024/01/06 15:43:32 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(char *str, int c)
{
	size_t	i;

	i = (size_t)-1;
	while (str[++i])
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
	}
	return (NULL);
}
