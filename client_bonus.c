/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:43:10 by aoulahra          #+#    #+#             */
/*   Updated: 2024/02/03 16:34:47 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int signal, siginfo_t *info, void *ucontext)
{
	static pid_t	pid = 0;

	(void)ucontext;
	(pid != info->si_pid) && (pid = info->si_pid);
	if (signal == SIGUSR1)
		ft_printf("Message well received :p\n");
}

void	process_bits(int c, int pid)
{
	int	size;
	int	binary;

	binary = ft_get_binary(c);
	size = ft_get_size(binary);
	(binary == 0) && (kill(pid, SIGUSR1));
	while (binary)
	{
		(binary % 10 == 0) && (kill(pid, SIGUSR1) == -1) && (print_error());
		(binary % 10 == 1) && (kill(pid, SIGUSR2) == -1) && (print_error());
		binary = binary / 10;
		usleep(1000);
	}
	while (size < 8)
	{
		(kill(pid, SIGUSR1) == -1) && (print_error());
		usleep(1000);
		size++;
	}
}

void	await_message(void)
{
	struct sigaction	sign;

	sign.sa_flags = SA_SIGINFO;
	sigemptyset(&sign.sa_mask);
	sigaddset(&sign.sa_mask, SIGUSR1);
	sigaddset(&sign.sa_mask, SIGUSR2);
	sign.sa_sigaction = &handler;
	sigaction(SIGUSR1, &sign, NULL);
}

void	send_empty_byte(pid_t pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		(kill(pid, SIGUSR1) == -1) && (print_error());
		usleep(700);
		i++;
	}
}

int	main(int ac, char **av)
{
	long	pid;
	char	*str;

	(ac == 3) && (pid = ft_atoi(av[1]));
	await_message();
	if (ac != 3)
	{
		ft_printf("not enough arguments try again\n");
		exit(EXIT_FAILURE);
	}
	if (pid == 0 || kill(pid, 0) == -1)
	{
		ft_printf("wrong pid try again :p\n");
		exit(EXIT_FAILURE);
	}
	str = av[2];
	while (*str)
	{
		process_bits(*str, pid);
		str++;
	}
	send_empty_byte(pid);
	exit(EXIT_SUCCESS);
}
