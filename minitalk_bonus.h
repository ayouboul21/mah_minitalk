/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:43:34 by aoulahra          #+#    #+#             */
/*   Updated: 2024/02/03 16:32:32 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include "signal.h"
# include "libs/printf/ft_printf.h"

long	ft_atoi(char *str);
int		ft_pow(int num, int pow);
int		ft_get_size(int num);
int		ft_get_binary(unsigned char num);
int		print_error(void);

#endif