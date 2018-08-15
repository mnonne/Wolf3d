/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 20:40:12 by aminadzh          #+#    #+#             */
/*   Updated: 2017/11/14 18:36:58 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*sorce;

	i = 0;
	dest = (unsigned char *)dst;
	sorce = (unsigned char *)src;
	while (i < n)
	{
		dest[i] = sorce[i];
		i++;
	}
	return (dst);
}
