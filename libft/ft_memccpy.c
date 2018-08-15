/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 21:53:10 by aminadzh          #+#    #+#             */
/*   Updated: 2017/11/14 18:38:14 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	stop;
	unsigned char	*dest;
	unsigned char	*sor;

	stop = (unsigned char)c;
	dest = (unsigned char *)dst;
	sor = (unsigned char *)src;
	while (n-- > 0)
	{
		*dest = *sor;
		if (*dest++ == stop)
			return (dest);
		sor++;
	}
	return (NULL);
}
