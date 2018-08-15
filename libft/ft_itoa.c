/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:57:28 by aminadzh          #+#    #+#             */
/*   Updated: 2017/11/18 18:06:08 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	long long int	nb;
	char			*str;
	int				d_num;
	int				sign;
	int				i;

	sign = 0;
	nb = n;
	if (n < 0)
	{
		sign = 1;
		nb = -nb;
	}
	d_num = ft_count_digits(nb);
	if (!(str = ft_strnew(d_num + sign)))
		return (NULL);
	i = 0;
	while (i < d_num)
	{
		str[i++] = nb % 10 + '0';
		nb /= 10;
	}
	if (sign)
		str[i] = '-';
	return (ft_strrev(str));
}
