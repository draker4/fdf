/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:08:55 by bperriol          #+#    #+#             */
/*   Updated: 2022/11/22 11:56:35 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_char_unsigned(unsigned int n)
{
	unsigned int	nb;

	nb = 0;
	while (n / 10 != 0)
	{
		n /= 10;
		nb++;
	}
	return (++nb);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char			*str;
	unsigned long	nb_char;
	unsigned int	i;

	nb_char = ft_nb_char_unsigned(n);
	str = malloc(sizeof(*str) * (nb_char + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (n / 10)
	{
		str[nb_char - 1 - i++] = n % 10 + 48;
		n /= 10;
	}
	str[nb_char - 1 - i] = n % 10 + 48;
	str[nb_char] = '\0';
	return (str);
}
