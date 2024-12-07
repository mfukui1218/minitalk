/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:55:17 by mfukui            #+#    #+#             */
/*   Updated: 2024/12/07 15:50:59 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_i;

void	ft_handler(int signum)
{
	g_i = signum;
}

int	ft_operate(void)
{
	static int	result = 0;
	static int	g_bit_count = 0;
	char		temp;

	if (g_i == SIGUSR1)
		result |= (0 << g_bit_count);
	else if (g_i == SIGUSR2)
		result |= (1 << g_bit_count);
	g_bit_count++;
	if (g_bit_count == 8)
	{
		write(1, &result, 1);
		g_bit_count = 0;
		temp = result;
		result = 0;
		return (temp);
	}
	return (-1);
}

void	ft_sig_fun(char *c, int pid)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (c[len])
	{
		i = 0;
		while (i < 8)
		{
			if ((c[len] >> i & 1) == 0)
				kill(pid, SIGUSR1);
			else if ((c[len] >> i & 1) == 1)
				kill(pid, SIGUSR2);
			usleep(100);
			i++;
		}
		len++;
	}
}

int	ft_atoi_rmkd(const char *str)
{
	size_t	i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while ('0' <= str[i] && str[i] <= '9')
	{
		if ((INT_MAX - (str[i] - '0')) / 10 < result * sign)
			return (-1);
		if ((INT_MIN + (str[i] - '0')) / 10 > result * sign)
			return (0);
		result = result * 10 + (str[i++] - '0');
	}
	return (result * sign);
}
