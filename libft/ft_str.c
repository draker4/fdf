/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:14:42 by bperriol          #+#    #+#             */
/*   Updated: 2022/11/22 11:57:04 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str(char *s)
{
	if (!s)
	{
		ft_putstr("(null)");
		return (ft_strlen("(null)"));
	}
	ft_putstr(s);
	return (ft_strlen(s));
}
