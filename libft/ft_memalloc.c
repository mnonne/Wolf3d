/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:38:44 by aminadzh          #+#    #+#             */
/*   Updated: 2017/11/09 18:22:34 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*ret;
	size_t			i;

	i = 0;
	if ((ret = (unsigned char *)malloc(size)))
	{
		while (i < size)
		{
			ret[i] = 0;
			i++;
		}
		return ((void *)ret);
	}
	return (NULL);
}
