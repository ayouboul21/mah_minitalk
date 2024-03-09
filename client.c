/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:23:23 by aoulahra          #+#    #+#             */
/*   Updated: 2024/02/03 16:48:21 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_get_size(int num)
{
	int	size;

	size = 1;
	while (num >= 10)
	{
		size++;
		num /= 10;
	}
	return (size);
}

int	ft_get_binary(unsigned char num)
{
	int		i;
	int		j;
	char	tmp;
	char	buffer[9];

	i = 0;
	while (num)
	{
		buffer[i] = num % 2 + '0';
		num /= 2;
		i++;
	}
	buffer[i] = '\0';
	j = 0;
	while (j < i--)
	{
		tmp = buffer[j];
		buffer[j] = buffer[i];
		buffer[i] = tmp;
		j++;
	}
	return (ft_atoi(buffer));
}

int	print_error(void)
{
	ft_printf("signal failed to send\n");
	exit(EXIT_FAILURE);
	return (1);
}

void	process_bits(int c, int pid)
{
	int	size;
	int	binary;

	binary = ft_get_binary(c);
	size = ft_get_size(binary);
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

int	main(int ac, char **av)
{
	long	pid;
	char	*str;

	(ac == 3) && (pid = ft_atoi(av[1]));
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
	exit(EXIT_SUCCESS);
}
