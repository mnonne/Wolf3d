/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:00:53 by aminadzh          #+#    #+#             */
/*   Updated: 2017/11/21 10:42:29 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*p_s1;
	unsigned char	*p_s2;
	size_t			s1_len;
	size_t			s2_len;
	size_t			i;

	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	while (i <= s1_len && i <= s2_len)
	{
		if (p_s1[i] != p_s2[i])
			return ((int)(p_s1[i] - p_s2[i]));
		i++;
	}
	return (0);
}
