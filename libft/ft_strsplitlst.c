/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:12:04 by aminadzh          #+#    #+#             */
/*   Updated: 2017/11/28 21:04:18 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_strsplitlst(char const *s, char c)
{
	t_list	*lst;
	t_list	*p_lst;
	t_list	*tmp;
	char	**tab;
	int		i;

	if (!s || !(tab = ft_strsplit(s, c)))
		return (NULL);
	i = 0;
	if (!(lst = ft_lstnew(tab[i], sizeof(char *))))
		return (NULL);
	p_lst = lst;
	while (tab[i++] != NULL)
	{
		if (!(tmp = ft_lstnew(tab[i], sizeof(char *))))
			return (NULL);
		ft_lstaddlast(p_lst, tmp);
	}
	return (lst);
}
