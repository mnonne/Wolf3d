/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:02:29 by aminadzh          #+#    #+#             */
/*   Updated: 2017/11/18 17:16:19 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	ch;
	int		i;

	str = (char *)s;
	ch = (char)c;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == ch)
			return (&str[i]);
		i--;
	}
	return (NULL);
}
