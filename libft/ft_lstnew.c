/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 18:59:08 by aminadzh          #+#    #+#             */
/*   Updated: 2017/11/19 16:27:51 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*l_new;

	if (!(l_new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(l_new->content = ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(l_new->content, content, content_size);
		l_new->content_size = content_size;
	}
	else
	{
		l_new->content = NULL;
		l_new->content_size = 0;
	}
	l_new->next = NULL;
	return (l_new);
}
