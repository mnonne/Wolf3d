/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:01:04 by aminadzh          #+#    #+#             */
/*   Updated: 2017/11/15 19:30:07 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len;
	size_t	i;
	int		q;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	q = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((ret = (char *)malloc(len * sizeof(char) + 1)))
	{
		while (s1[q] != '\0')
		{
			ret[i++] = s1[q++];
		}
		q = 0;
		while (s2[q] != '\0')
		{
			ret[i++] = s2[q++];
		}
		ret[i] = '\0';
		return (ret);
	}
	return (NULL);
}
