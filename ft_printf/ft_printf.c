/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 00:52:21 by mfukui            #+#    #+#             */
/*   Updated: 2023/10/03 21:20:14 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_fun_sel(const char c, va_list args)
{
	size_t	count;
	size_t	num;

	count = 0;
	if (c == 'c')
		count += ft_putchar_c((char)va_arg(args, int));
	else if (c == 's')
		count += ft_putstr_c(va_arg(args, char *));
	else if (c == 'p')
		count += ft_putp_c(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
	{
		num = va_arg(args, int);
		ft_putnbr(num);
		count += ft_num_len(num);
	}
	else if (c == 'u')
		count += ft_putu_c(va_arg(args, unsigned int));
	else if (c == 'x')
		count += ft_putsx_c(va_arg(args, unsigned int));
	else if (c == 'X')
		count += ft_putlx_c(va_arg(args, unsigned int));
	else if (c == '%')
		count = ft_putchar_c('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	size_t	result;

	i = 0;
	result = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			result += ft_fun_sel(format[i], args);
		}
		else
		{
			ft_putchar(format[i]);
			result++;
		}
		i++;
	}
	va_end(args);
	return (result);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *p;
// 	p = "42";
// 	// ft_printf("%%\n%u\n%x\n", 42,p);
// 	printf("%i\n", printf("%i\n%d\n%s\n%s\n", 0, INT_MIN, "",NULL));
// 	printf("%i\n", printf("%u\n%p\n%x\n%X\n",2147483647,p,1234567,1234567));
// 	printf("%s\n",  "---------------------------------------------");
// 	printf("%i\n", ft_printf("%i\n%d\n%s\n%s\n", 0, INT_MIN, "",NULL));
// 	printf("%i\n", ft_printf("%u\n%p\n%x\n%X\n",2147483647,p,1234567,1234567));
// 	return (0);
// }
