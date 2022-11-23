/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:18:21 by bperriol          #+#    #+#             */
/*   Updated: 2022/11/23 10:32:07 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

t_list	*ft_parse(t_list *list, char *file)
{
	int		fd;
	char	*str;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	str = get_next_line(fd);
	if (!str)
		return (NULL);
	while (str)
	{
		if (!ft_add_str(list, str))
		{
			ft_lstclear_map(&list);
			return (NULL);
		}
		str = get_next_line(fd);
		if (!str)
			return (NULL);
	}
	return (list);
}
