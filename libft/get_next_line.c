/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:13:23 by aminadzh          #+#    #+#             */
/*   Updated: 2018/04/22 19:32:13 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_swap(char *str, char *heap)
{
	char	*tmp;

	tmp = ft_strdup(str);
	free(str);
	str = ft_strjoin(tmp, heap);
	free(tmp);
	return (str);
}

t_stack	*new_node(char *heap, int fd)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->str = ft_strdup(heap);
	new->desc = fd;
	return (new);
}

int		find_line(t_list **stack, char **line, int fd)
{
	t_list	*p_stack;
	char	*ptr;
	int		st;
	int		end;
	int		dif;

	st = 0;
	p_stack = *stack;
	while (((t_stack *)p_stack->content)->desc != fd)
		p_stack = p_stack->next;
	ptr = ((t_stack *)p_stack->content)->str;
	while (ptr[st] != '\n' && ptr[st] != '\0')
		st++;
	end = st;
	while (ptr[end] != '\0')
		end++;
	if (*ptr == '\0')
		return (0);
	*line = ft_strsub(ptr, 0, st);
	if ((dif = end - st) == 0)
		ft_bzero(ptr, end);
	ft_memmove(ptr, ptr + st + 1, dif);
	while (dif++ < end)
		ptr[dif] = '\0';
	return (1);
}

void	gnl_read(int fd, t_list **stack, char *heap)
{
	t_list	*temp;
	t_list	*ptr;
	t_stack *lst_cont;

	ptr = *stack;
	while (ptr && DESC != fd)
		ptr = ptr->next;
	if (ptr && DESC == fd)
		STR = gnl_swap(STR, heap);
	if ((ptr && DESC != fd) || (!ptr && *stack))
	{
		lst_cont = new_node(heap, fd);
		temp = ft_lstnew(lst_cont, sizeof(t_stack));
		ft_lstadd(stack, temp);
	}
	if (!*stack && !ptr)
	{
		lst_cont = new_node(heap, fd);
		*stack = ft_lstnew(lst_cont, sizeof(t_stack));
		free(lst_cont);
	}
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*stack;
	char			*heap;
	int				ret;

	if (fd < 0 || !line || !(heap = ft_strnew(sizeof(char) *
					BUFF_SIZE + 1)))
		return (-1);
	*line = NULL;
	while ((ret = read(fd, heap, BUFF_SIZE)) > 0)
	{
		gnl_read(fd, &stack, heap);
		if (ft_strchr(heap, '\n'))
			break ;
		ft_bzero(heap, BUFF_SIZE + 1);
	}
	free(heap);
	if (ret < 0)
		return (ret);
	return (ret = find_line(&stack, line, fd));
}
