/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 17:44:39 by aminadzh          #+#    #+#             */
/*   Updated: 2018/06/03 15:58:28 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		fill_square(t_point p, int obstacle, int cell, t_wolf *wolf)
{
	t_color	color;
	int		x;
	int		y;

	if (obstacle == 1)
		color = (t_color){.r = 255, .g = 255, .b = 255, .alpha = 100};
	else if (obstacle == 2)
		color = (t_color){.r = 255, .g = 0, .b = 0, .alpha = 100};
	else
		color = (t_color){.r = 0, .g = 255, .b = 0, .alpha = 100};
	y = p.y;
	while (y < p.y + cell)
	{
		x = p.x;
		while (x < p.x + cell)
		{
			ft_putpixel(x, y, color, wolf->minimap);
			x++;
		}
		y++;
	}
}

void		draw_player(t_wolf *wolf)
{
	t_point	p;

	p.x = (int)(PLAYER.y * wolf->minimap->width / MAP->height);
	p.y = (int)(PLAYER.x * wolf->minimap->width / MAP->height);
	fill_square(p, 2, 3, wolf);
}

void		minimap(t_wolf *wolf)
{
	t_point	p;
	int		cell;
	int		a;
	int		b;

	cell = ceil((double)wolf->minimap->width / (double)wolf->map->height);
	p.y = 0;
	a = 0;
	while (p.y < wolf->minimap->width && a < HEIGHT)
	{
		p.x = 0;
		b = 0;
		while (p.x < wolf->minimap->width && b < HEIGHT)
		{
			fill_square(p, ARRAY[a][b], cell, wolf);
			p.x += cell;
			b++;
		}
		p.y += cell;
		a++;
	}
	draw_player(wolf);
	mlx_put_image_to_window(MLX, WIN, wolf->minimap->img, 0,
			WIN_H - wolf->minimap->width);
}
