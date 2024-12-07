/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:37:41 by mfukui            #+#    #+#             */
/*   Updated: 2023/10/03 17:35:49 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putu_c(unsigned int nb)
{
	if (nb >= 10)
		return (ft_putu_c(nb / 10) + ft_putchar_c(nb % 10 + '0'));
	else
		return (ft_putchar_c(nb + '0'));
}
