/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:13:29 by aminadzh          #+#    #+#             */
/*   Updated: 2017/11/21 10:27:57 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;
	size_t			str1_len;
	size_t			str2_len;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	str1_len = ft_strlen(s1);
	str2_len = ft_strlen(s2);
	while (i <= str1_len && i <= str2_len && i < n)
	{
		if (str1[i] != str2[i])
			return ((int)(str1[i] - str2[i]));
		i++;
	}
	return (0);
}
