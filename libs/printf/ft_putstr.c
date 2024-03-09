/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:21:35 by aoulahra          #+#    #+#             */
/*   Updated: 2023/11/21 21:16:33 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	counter;

	if (!s)
		return (ft_putstr("(null)"));
	i = -1;
	counter = 0;
	while (s[++i])
		counter += ft_putchar(s[i]);
	return (counter);
}
