/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:22:37 by mfukui            #+#    #+#             */
/*   Updated: 2023/10/03 17:35:49 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb)
{
	long	num;

	num = nb;
	if (num < 0)
	{
		num *= -1;
		ft_putchar('-');
	}
	if (num / 10 != 0)
		ft_putnbr(num / 10);
	ft_putchar(num % 10 + '0');
}

// int main()
// {
// 	int num = 12345;
// 	ft_putnbr(num);
// 	return 0;
// }
