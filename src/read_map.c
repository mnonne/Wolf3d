/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 17:22:39 by aminadzh          #+#    #+#             */
/*   Updated: 2018/05/31 18:54:21 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			count_lines(char *file)
{
	int		i;
	int		fd;
	char	*line;
	char	buff[10];

	i = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (-1);
	if ((read(fd, buff, 10)) <= 0)
		return (-1);
	close(fd);
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		free(line);
	}
	close(fd);
	return (i);
}

int			*fill_map(char *line, t_wolf *wolf, int n)
{
	int		*arr;
	int		i;
	int		b;

	arr = (int *)malloc(sizeof(int) * HEIGHT);
	i = 0;
	b = 1;
	while (i < HEIGHT)
	{
		if ((*line < '0' || (*line > '3' && *line != 'p')) ||
				((n == 0 || n == HEIGHT - 1) && *line != '1') ||
				((i == 0 || i == HEIGHT - 1) && *line != '1'))
		{
			free(arr);
			return (NULL);
		}
		arr[i] = *line - '0';
		if (arr[i] > 1 && arr[i] <= 9)
			wolf->map->num_sprites++;
		i++;
		line += 2;
		b += 2;
	}
	return (arr);
}

int			fill_objects(t_wolf *wolf, int *err_no)
{
	t_point	p;
	int		i;

	p.y = 0;
	i = 0;
	SPRITE = (t_object *)malloc(sizeof(t_object) * N_SPRITES);
	SPRITE_DIST = (double *)malloc(sizeof(double) * N_SPRITES);
	SPRITE_ORDER = (int *)malloc(sizeof(int) * N_SPRITES);
	while (p.y < HEIGHT)
	{
		p.x = 0;
		while (p.x < HEIGHT)
		{
			if (ARRAY[p.y][p.x] > 1 && ARRAY[p.y][p.x] != 64)
				set_object(&wolf, ARRAY[p.y][p.x], i++, p);
			if (ARRAY[p.y][p.x] == 64)
			{
				if (set_player(p.x, p.y, wolf) < 0)
					return (*err_no = -1);
			}
			p.x++;
		}
		p.y++;
	}
	return (0);
}

int			check_line(int fd, t_wolf *wolf, int *err_no)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if ((int)ft_strlen(line) != HEIGHT * 2 - 1)
		{
			free(line);
			return (*err_no = -3);
		}
		if (!(ARRAY[i] = fill_map(line, wolf, i)))
		{
			close(fd);
			free(line);
			return (*err_no = -4);
		}
		i++;
		free(line);
	}
	return (1);
}

int			read_map(char *file, t_wolf *wolf, int *err_no)
{
	int		fd;

	wolf->map->player_pos.x = 0;
	if ((HEIGHT = count_lines(file)) < 3)
		return (*err_no = -2);
	if (!(ARRAY = (int **)malloc(sizeof(int) * HEIGHT * HEIGHT)))
		return (0);
	fd = open(file, O_RDONLY);
	if (check_line(fd, wolf, err_no) < 0)
		return (-1);
	close(fd);
	if (fill_objects(wolf, err_no) < 0)
		return (-1);
	if (wolf->map->player_pos.x == 0)
		return (*err_no = -1);
	return (1);
}
