/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:15:17 by aminadzh          #+#    #+#             */
/*   Updated: 2017/11/28 19:12:30 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddlast(t_list *lst, t_list *new)
{
	t_list	*current;

	if (lst && new)
	{
		current = lst;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new;
		new->next = NULL;
	}
}
