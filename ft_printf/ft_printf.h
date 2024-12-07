/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:07:28 by mfukui            #+#    #+#             */
/*   Updated: 2023/10/03 19:06:40 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>

void	ft_putchar(int c);
size_t	ft_putchar_c(int c);
size_t	ft_putstr_c(char *str);
size_t	ft_putu_c(unsigned int nb);
void	ft_putnbr(int nb);
size_t	ft_num_len(int nb);
size_t	ft_putp_c(void *pt);
void	*ft_memset(void *buf, int ch, size_t n);
size_t	ft_putsx_c(unsigned int nb);
size_t	ft_putlx_c(unsigned int nb);
size_t	ft_num_len(int n);
int		ft_printf(const char *format, ...);

#endif