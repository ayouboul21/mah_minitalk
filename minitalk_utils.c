/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:27:59 by aoulahra          #+#    #+#             */
/*   Updated: 2024/01/31 20:42:12 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	find_sign(size_t *i, int *sign, const char *str)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

int	all_digits(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str > '9' || *str < '0')
			return (0);
		str++;
	}
	return (1);
}

long	ft_atoi(char *str)
{
	size_t	i;
	int		res;
	int		pre;
	int		sign;

	if (!all_digits(str))
		return (2147483648);
	(1 == 1) && (i = 0, res = 0, pre = 0, sign = 1);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	find_sign(&i, &sign, str);
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = res * 10 + (str[i] - '0') * sign;
		if (res / 10 != pre)
			return (2147483648);
		pre = res;
		i++;
	}
	return (res);
}

int	ft_pow(int num, int pow)
{
	if (pow == 0)
		return (1);
	return (num * ft_pow(num, pow - 1));
}
