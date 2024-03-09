/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:33:28 by aoulahra          #+#    #+#             */
/*   Updated: 2023/12/09 21:16:14 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putchar(int c);
int		ft_putstr(char *s);
void	ft_putnbr(int n, int *counter);
void	ft_putnbr_u(unsigned int n, int *counter);
int		ft_printf(const char *str, ...);
void	ft_puthexa(unsigned long nb, char *base, int *counter);

#endif
