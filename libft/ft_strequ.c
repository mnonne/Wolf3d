/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:05:42 by aminadzh          #+#    #+#             */
/*   Updated: 2017/11/23 17:29:58 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_len;

	if (!s1 || !s2)
		return (0);
	i = 0;
	s1_len = ft_strlen(s1);
	if (s1_len != ft_strlen(s2))
		return (0);
	while (i < s1_len)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
