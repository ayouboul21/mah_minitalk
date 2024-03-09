/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:10:14 by aoulahra          #+#    #+#             */
/*   Updated: 2023/12/05 16:09:11 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_based_on_format(char c, int *counter, va_list lst)
{
	char	*base1;
	char	*base2;

	base1 = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	if (c == 's')
		*counter += ft_putstr(va_arg(lst, char *));
	else if (c == 'c')
		*counter += ft_putchar(va_arg(lst, int));
	else if (c == 'x')
		ft_puthexa(va_arg(lst, unsigned int), base1, counter);
	else if (c == 'X')
		ft_puthexa(va_arg(lst, unsigned int), base2, counter);
	else if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(lst, int), counter);
	else if (c == 'u')
		ft_putnbr_u(va_arg(lst, unsigned int), counter);
	else if (c == 'p')
	{
		*counter += ft_putstr("0x");
		ft_puthexa((unsigned long)va_arg(lst, void *), base1, counter);
	}
	else if (c == '%')
		*counter += ft_putchar('%');
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		counter;

	counter = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	va_start(lst, str);
	while (*str)
	{
		if (*str == '%')
		{
			print_based_on_format(*(str + 1), &counter, lst);
			str++;
		}
		else if (*str)
			counter += ft_putchar(*str);
		str++;
	}
	va_end(lst);
	return (counter);
}
