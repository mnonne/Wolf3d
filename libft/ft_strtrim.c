/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:32:54 by aminadzh          #+#    #+#             */
/*   Updated: 2017/11/23 18:09:48 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_whtsp(char const *s)
{
	size_t	len;
	size_t	i;
	size_t	end;

	len = ft_strlen(s);
	end = len - 1;
	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (i);
	while (s[end] == ' ' || s[end] == '\t' || s[end] == '\n')
	{
		end--;
		i++;
	}
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char	*ret;
	size_t	i;
	size_t	q;
	size_t	len;
	size_t	whtsp;

	if (!s)
		return (NULL);
	i = 0;
	q = 0;
	len = ft_strlen(s);
	whtsp = ft_count_whtsp(s);
	if (!(ret = (char *)malloc((len - whtsp) * sizeof(char) + 1)))
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (q < (len - whtsp) && s[i] != '\0')
	{
		ret[q] = s[i];
		i++;
		q++;
	}
	ret[q] = '\0';
	return (ret);
}
