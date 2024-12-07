/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsx_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:35:36 by mfukui            #+#    #+#             */
/*   Updated: 2023/10/03 21:18:28 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putsx_c(unsigned int nb)
{
	char			*hex;
	char			buff[20];
	size_t			i;
	size_t			count;

	ft_memset(buff, 0, sizeof(buff));
	count = 0;
	hex = "0123456789abcdef";
	i = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		count++;
	}
	while (nb)
	{
		buff[i++] = hex[nb % 16];
		nb /= 16;
	}
	while (i)
	{
		write (1, &buff[--i], 1);
		count++;
	}
	return (count);
}

// #include <stdio.h>
// int main(void)
// {
// 	ft_putsx(123456789);
// 	return (0);
// }
