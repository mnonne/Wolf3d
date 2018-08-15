/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:27:18 by aminadzh          #+#    #+#             */
/*   Updated: 2017/11/18 16:47:30 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;

	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	if (p_src > p_dst)
	{
		while (len > 0)
		{
			*p_dst++ = *p_src++;
			len--;
		}
	}
	else
	{
		while (len--)
			p_dst[len] = p_src[len];
	}
	return (dst);
}
