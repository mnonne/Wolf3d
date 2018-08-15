/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:56:03 by aminadzh          #+#    #+#             */
/*   Updated: 2017/11/15 17:35:07 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	q;
	size_t	n_size;

	i = 0;
	q = 0;
	n_size = ft_strlen(needle);
	if (n_size == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i + q] == needle[q] && i + q < len)
		{
			if (q == n_size - 1)
				return ((char *)(haystack + i));
			q++;
		}
		i++;
		q = 0;
	}
	return (NULL);
}
