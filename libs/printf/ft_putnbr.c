/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:27:22 by aoulahra          #+#    #+#             */
/*   Updated: 2023/11/21 21:16:30 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *counter)
{
	if (n == -2147483648)
		*counter += ft_putstr("-2147483648");
	else if (n < 0)
	{
		*counter += ft_putchar('-');
		ft_putnbr(-n, counter);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, counter);
		ft_putnbr(n % 10, counter);
	}
	else
		*counter += ft_putchar(n + '0');
}
