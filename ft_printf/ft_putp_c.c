/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 00:38:28 by mfukui            #+#    #+#             */
/*   Updated: 2023/10/03 17:35:49 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putp_c(void *pt)
{
	char				*hex;
	char				buff[20];
	size_t				i;
	size_t				temp;
	unsigned long long	nb;

	nb = (unsigned long long)pt;
	ft_memset(buff, 0, sizeof(buff));
	write(1, "0x", 2);
	if (nb == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	hex = "0123456789abcdef";
	i = 0;
	while (nb)
	{
		buff[i++] = hex[nb % 16];
		nb /= 16;
	}
	temp = i;
	while (i > 0)
		write (1, &buff[--i], 1);
	return (temp + 2);
}

// int main(void)
// {
// 	char *a;

// 	a = "42";
// 	ft_putp(0);
// 	return (0);
// }
