/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:35:08 by aminadzh          #+#    #+#             */
/*   Updated: 2017/11/11 20:53:07 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	q;
	size_t	n_size;

	i = 0;
	q = 0;
	n_size = ft_strlen(needle);
	if (n_size == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		while (haystack[i + q] == needle[q])
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
