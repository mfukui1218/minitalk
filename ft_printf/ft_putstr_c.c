/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:56:05 by mfukui            #+#    #+#             */
/*   Updated: 2023/10/03 17:35:49 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putstr_c(char *str)
{
	size_t	count;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	count = 0;
	while (*str)
	{
		write(1, str++, 1);
		count++;
	}
	return (count);
}

// int main() {
//     char message[] = "Im sory";
//     ft_putstr(message);
//     return (0);
// }