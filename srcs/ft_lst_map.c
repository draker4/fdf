/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:31:06 by bperriol          #+#    #+#             */
/*   Updated: 2022/11/23 10:38:33 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

t_list	*ft_new_elem_map(t_point point)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list *));
	if (!elem)
		return (NULL);
	elem->point = point;
	elem->next = NULL;
	return (elem);
}

void	ft_lstclear_map(t_list **lst)
{
	t_list	*current;
	t_list	*previous;

	if (!lst || *lst == NULL || del == NULL)
		return ;
	current = *lst;
	while (current)
	{
		free(current->point);
		previous = current;
		current = current->next;
		free(previous);
	}
	*lst = NULL;
}
