/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:36:45 by bperriol          #+#    #+#             */
/*   Updated: 2022/11/22 11:56:54 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(unsigned long long nb, int *count, int maj)
{
	if (nb >= 16)
		ft_putnbr_base(nb / 16, count, maj);
	*count += 1;
	if (!maj)
		ft_putchar("0123456789abcdef"[nb % 16]);
	else
		ft_putchar("0123456789ABCDEF"[nb % 16]);
}
