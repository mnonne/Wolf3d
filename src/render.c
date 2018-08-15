/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 18:51:08 by aminadzh          #+#    #+#             */
/*   Updated: 2018/05/30 17:50:04 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_point		prepare_dda(t_vec ray, t_dda *dda, t_wolf *wolf)
{
	t_point	step;

	if (ray.x < 0)
	{
		step.x = -1;
		SIDE_DIST_X = (PLAYER.x - wolf->map_x) * dda->delta.x;
	}
	else
	{
		step.x = 1;
		SIDE_DIST_X = ((double)wolf->map_x + 1.0 - PLAYER.x) * dda->delta.x;
	}
	if (ray.y < 0)
	{
		step.y = -1;
		SIDE_DIST_Y = (PLAYER.y - (double)wolf->map_y) * dda->delta.y;
	}
	else
	{
		step.y = 1;
		SIDE_DIST_Y = ((double)wolf->map_y + 1.0 - PLAYER.y) * dda->delta.y;
	}
	return (step);
}

int			perform_dda(t_dda *dda, t_point step, t_wolf *wolf)
{
	int		hit;
	int		side;

	hit = 0;
	while (hit == 0)
	{
		if (SIDE_DIST_X < SIDE_DIST_Y)
		{
			SIDE_DIST_X += dda->delta.x;
			wolf->map_x += step.x;
			side = 0;
		}
		else
		{
			SIDE_DIST_Y += dda->delta.y;
			wolf->map_y += step.y;
			side = 1;
		}
		if (ARRAY[wolf->map_x][wolf->map_y] == 1)
			hit = 1;
	}
	return (side);
}

void		order_objects(t_wolf *wolf)
{
	int		i;

	i = 0;
	while (i < N_SPRITES)
	{
		SPRITE_ORDER[i] = i;
		SPRITE_DIST[i] = ((PLAYER.x - SPRITE[i].x) * (PLAYER.x - SPRITE[i].x)
				+ (PLAYER.y - SPRITE[i].y) * (PLAYER.y - SPRITE[i].y));
		i++;
	}
	comb_sort(SPRITE_ORDER, SPRITE_DIST, N_SPRITES);
}

void		render(t_wolf *wolf)
{
	int		x;
	int		side;

	x = 0;
	while (x <= WIN_W)
	{
		wolf->camera = 2 * x / (double)WIN_W - 1;
		RAY.x = DIR.x + PLANE.x * wolf->camera;
		RAY.y = DIR.y + PLANE.y * wolf->camera;
		wolf->map_x = (int)PLAYER.x;
		wolf->map_y = (int)PLAYER.y;
		WALL_DIST = dist_to_wall(&side, wolf);
		wolf->z_buffer[x] = WALL_DIST;
		draw_column(side, x, wolf);
		x++;
	}
	order_objects(wolf);
	cast_sprites(wolf);
	mlx_put_image_to_window(MLX, WIN, IMAGE->img, 0, 0);
	mlx_put_image_to_window(MLX, WIN, GUN_TEXT.ptr,
			WIN_W / 2 - GUN_TEXT.wdth / 2, WIN_H - GUN_TEXT.height);
	count_time(wolf);
}
