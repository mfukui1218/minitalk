/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:23:13 by mfukui            #+#    #+#             */
/*   Updated: 2023/11/11 01:52:50 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

extern volatile sig_atomic_t	g_i;

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	str;

	if (argc < 2)
	{
		g_i = 0;
		ft_printf("Server PID: %d\n", getpid());
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		while (1)
		{
			pause();
			str = ft_operate();
		}
	}
	else
	{
		pid = ft_atoi_rmkd(argv[1]);
		ft_sig_fun(argv[2], pid);
	}
	return (0);
}
