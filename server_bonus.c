/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:43:21 by aoulahra          #+#    #+#             */
/*   Updated: 2024/02/03 15:56:08 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	print_char(char *c)
{
	int	result;
	int	i;

	(1 == 1) && (i = 0, result = 0);
	while (i < 8)
	{
		result += (c[i] - '0') * ft_pow(2, i);
		i++;
	}
	(result != 0) && (ft_printf("%c", result));
}

int	is_empty(char c[])
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c[i] == '1')
			return (0);
		i++;
	}
	return (1);
}

void	handler(int signal, siginfo_t *info, void *ucontext)
{
	static char		c[8];
	static int		i = 0;
	static pid_t	pid = 0;

	(void)ucontext;
	(pid != info->si_pid) && (pid = info->si_pid, i = 0);
	(signal == SIGUSR1 && i < 8) && (c[i] = '0', i++);
	(signal == SIGUSR2 && i < 8) && (c[i] = '1', i++);
	if (i == 8)
	{
		i = 0;
		print_char(c);
		(is_empty(c)) && (kill(pid, SIGUSR1) == -1) &&
			(ft_printf("message failed to send"));
	}
}

int	main(void)
{
	struct sigaction	sign;

	sign.sa_flags = SA_SIGINFO;
	sigemptyset(&sign.sa_mask);
	sigaddset(&sign.sa_mask, SIGUSR1);
	sigaddset(&sign.sa_mask, SIGUSR2);
	sign.sa_sigaction = &handler;
	ft_printf("SERVER PID : %d\n", getpid());
	sigaction(SIGUSR1, &sign, NULL);
	sigaction(SIGUSR2, &sign, NULL);
	while (1)
		pause();
}
