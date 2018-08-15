/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 15:48:53 by aminadzh          #+#    #+#             */
/*   Updated: 2017/11/19 18:19:24 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*p_new;

	if (!*f || !lst)
		return (NULL);
	tmp = (*f)(lst);
	if (!(new = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	lst = lst->next;
	p_new = new;
	while (lst)
	{
		tmp = (*f)(lst);
		p_new->next = ft_lstnew(tmp->content, tmp->content_size);
		p_new = p_new->next;
		lst = lst->next;
	}
	return (new);
}
