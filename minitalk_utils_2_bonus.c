/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:15:33 by aoulahra          #+#    #+#             */
/*   Updated: 2024/02/03 16:32:25 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
