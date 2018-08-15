/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:55:03 by aminadzh          #+#    #+#             */
/*   Updated: 2017/11/15 19:24:20 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(ret = (char *)malloc(ft_strlen(s) * sizeof(char) + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		ret[i] = (*f)(s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
