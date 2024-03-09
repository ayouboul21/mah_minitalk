/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:31:46 by aoulahra          #+#    #+#             */
/*   Updated: 2023/11/21 21:16:26 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u(unsigned int n, int *counter)
{
	if (n > 9)
	{
		ft_putnbr_u(n / 10, counter);
		ft_putnbr_u(n % 10, counter);
	}
	else
		*counter += ft_putchar(n + '0');
}
