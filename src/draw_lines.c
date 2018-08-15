/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:33:53 by aminadzh          #+#    #+#             */
/*   Updated: 2018/05/30 15:54:49 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		draw_wall(int x, int side, t_wolf *wolf)
{
	int		start;
	int		i;

	start = wolf->start;
	if (side == 1 && wolf->map_y < PLAYER.y)
		i = 0;
	else if (side == 1 && wolf->map_y > PLAYER.y)
		i = 1;
	else if (side == 0 && wolf->map_x < PLAYER.x)
		i = 2;
	else
		i = 3;
	while (start < wolf->end)
	{
		TEXT_Y = (start - WIN_H / 2 + wolf->line_len / 2) *
					WALL_TEXT(i).wdth / wolf->line_len;
		COLOR.b = WALL_TEXT(i).data[wolf->text_x * WALL_TEXT(i).bpp +
				TEXT_Y * WALL_TEXT(i).sl];
		COLOR.g = WALL_TEXT(i).data[wolf->text_x * WALL_TEXT(i).bpp +
				TEXT_Y * WALL_TEXT(i).sl + 1];
		COLOR.r = WALL_TEXT(i).data[wolf->text_x * WALL_TEXT(i).bpp +
				TEXT_Y * WALL_TEXT(i).sl + 2];
		COLOR.alpha = 0;
		ft_putpixel(x, start++, COLOR, wolf->image);
	}
}

t_vec		prepare_surfaces(int side, double wall_x, t_wolf *wolf)
{
	t_vec	floor;

	if (side == 0 && RAY.x > 0)
	{
		floor.x = wolf->map_x;
		floor.y = wolf->map_y + wall_x;
	}
	else if (side == 0 && RAY.x < 0)
	{
		floor.x = wolf->map_x + 1;
		floor.y = wolf->map_y + wall_x;
	}
	else if (side == 1 && RAY.y > 0)
	{
		floor.x = wolf->map_x + wall_x;
		floor.y = wolf->map_y;
	}
	else
	{
		floor.x = wolf->map_x + wall_x;
		floor.y = wolf->map_y + 1;
	}
	return (floor);
}

void		draw_floor(int x, t_vec floor, t_wolf *wolf)
{
	int		start_floor;
	double	curr_dist;
	t_vec	curr_floor;

	start_floor = wolf->end;
	while (start_floor < WIN_H)
	{
		curr_dist = (double)WIN_H / (2 * (double)start_floor - (double)WIN_H);
		curr_floor.x = curr_dist / WALL_DIST * floor.x +
				(1 - (curr_dist / WALL_DIST)) * PLAYER.x;
		curr_floor.y = curr_dist / WALL_DIST * floor.y +
				(1 - (curr_dist / WALL_DIST)) * PLAYER.y;
		wolf->text_x = (int)(curr_floor.x * FLOOR_TEXT.wdth) % FLOOR_TEXT.wdth;
		TEXT_Y = (int)(curr_floor.y * FLOOR_TEXT.height) %
			FLOOR_TEXT.height;
		COLOR.b = FLOOR_TEXT.data[wolf->text_x *
			FLOOR_TEXT.bpp + TEXT_Y * FLOOR_TEXT.sl];
		COLOR.g = FLOOR_TEXT.data[wolf->text_x *
			FLOOR_TEXT.bpp + TEXT_Y * FLOOR_TEXT.sl + 1];
		COLOR.r = FLOOR_TEXT.data[wolf->text_x *
			FLOOR_TEXT.bpp + TEXT_Y * FLOOR_TEXT.sl + 2];
		COLOR.alpha = 0;
		ft_putpixel(x, start_floor, COLOR, wolf->image);
		start_floor++;
	}
}

void		draw_ceiling(int x, t_vec floor, t_wolf *wolf)
{
	int		start_ceil;
	double	curr_dist;
	t_vec	curr_floor;

	start_ceil = wolf->start - 1;
	while (start_ceil > 0)
	{
		curr_dist = -(double)WIN_H / (2 * (double)start_ceil - (double)WIN_H);
		curr_floor.x = curr_dist / WALL_DIST * floor.x +
				(1 - (curr_dist / WALL_DIST)) * PLAYER.x;
		curr_floor.y = curr_dist / WALL_DIST * floor.y +
				(1 - (curr_dist / WALL_DIST)) * PLAYER.y;
		TEXT_X = (int)(curr_floor.x * WALL_TEXT(CT).wdth) % WALL_TEXT(CT).wdth;
		TEXT_Y = (int)(curr_floor.y * WALL_TEXT(CT).height) %
			WALL_TEXT(CT).height;
		COLOR.b = WALL_TEXT(CT).data[TEXT_X *
			WALL_TEXT(CT).bpp + TEXT_Y * WALL_TEXT(CT).sl];
		COLOR.g = WALL_TEXT(CT).data[TEXT_X *
			WALL_TEXT(CT).bpp + TEXT_Y * WALL_TEXT(CT).sl + 1];
		COLOR.r = WALL_TEXT(CT).data[TEXT_X *
			WALL_TEXT(CT).bpp + TEXT_Y * WALL_TEXT(CT).sl + 2];
		COLOR.alpha = 0;
		ft_putpixel(x, start_ceil, COLOR, wolf->image);
		start_ceil--;
	}
}

void		draw_column(int side, int x, t_wolf *wolf)
{
	double	wall_x;
	t_vec	floor;

	wolf->line_len = (int)(WIN_H / WALL_DIST);
	if ((wolf->start = -wolf->line_len / 2 + WIN_H / 2) < 0)
		wolf->start = 0;
	if ((wolf->end = wolf->line_len / 2 + WIN_H / 2) > WIN_H)
		wolf->end = WIN_H - 1;
	if (side == 0)
		wall_x = PLAYER.y + WALL_DIST * RAY.y;
	else
		wall_x = PLAYER.x + WALL_DIST * RAY.x;
	wall_x -= (int)wall_x;
	TEXT_X = (int)(wall_x * (double)wolf->texture[0].wdth);
	if (side == 0 && RAY.x > 0)
		TEXT_X = wolf->texture[0].wdth - TEXT_X;
	if (side == 1 && RAY.y < 0)
		TEXT_X = wolf->texture[0].wdth - TEXT_X;
	draw_wall(x, side, wolf);
	floor = prepare_surfaces(side, wall_x, wolf);
	draw_floor(x, floor, wolf);
	draw_ceiling(x, floor, wolf);
}
