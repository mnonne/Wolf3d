/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 20:01:30 by aminadzh          #+#    #+#             */
/*   Updated: 2018/03/24 13:40:10 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 40000
# define STR ((t_stack *)(ptr)->content)->str
# define DESC ((t_stack *)(ptr)->content)->desc

typedef struct	s_stack
{
	char		*str;
	int			desc;
}				t_stack;

int				get_next_line(const int fd, char **line);

#endif
