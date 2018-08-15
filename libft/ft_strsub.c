/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:45:22 by aminadzh          #+#    #+#             */
/*   Updated: 2017/11/15 19:28:55 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if ((ret = (char *)malloc(len * sizeof(char) + 1)))
	{
		while (i < len)
		{
			ret[i++] = s[start++];
		}
		ret[i] = '\0';
		return (ret);
	}
	return (NULL);
}
