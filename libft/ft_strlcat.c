/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:17:32 by aminadzh          #+#    #+#             */
/*   Updated: 2017/11/15 17:11:13 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;
	size_t		d_len;
	size_t		i;

	d = dst;
	s = src;
	i = dstsize;
	while (i-- != 0 && *d != '\0')
		d++;
	d_len = d - dst;
	i = dstsize - d_len;
	if (i == 0)
		return (d_len + ft_strlen(src));
	while (*s != '\0')
	{
		if (i != 1)
		{
			*d++ = *s;
			i--;
		}
		s++;
	}
	*d = '\0';
	return (d_len + (s - src));
}
