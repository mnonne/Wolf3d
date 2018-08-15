/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obstacles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 16:37:00 by aminadzh          #+#    #+#             */
/*   Updated: 2018/05/30 19:27:45 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			sprite_position(t_wolf *wolf, int i)
{
	double	inv_det;
	int		spr_scr_x;

	SPR_POS_X = SPRITE[SPRITE_ORDER[i]].x - PLAYER.x;
	SPR_POS_Y = SPRITE[SPRITE_ORDER[i]].y - PLAYER.y;
	inv_det = 1.0 / (PLANE.x * DIR.y - DIR.x * PLANE.y);
	TRANS_X = inv_det * (DIR.y * SPR_POS_X - DIR.x * SPR_POS_Y);
	TRANS_Y = inv_det * (-PLANE.y * SPR_POS_X + PLANE.x * SPR_POS_Y);
	spr_scr_x = (int)((WIN_W / 2) * (1.0 + TRANS_X / TRANS_Y));
	wolf->spr_height = abs((int)(WIN_H / TRANS_Y));
	wolf->spr_start.y = -wolf->spr_height / 2 + WIN_H / 2;
	if (wolf->spr_start.y < 0)
		wolf->spr_start.y = 0;
	wolf->spr_end.y = wolf->spr_height / 2 + WIN_H / 2;
	if (wolf->spr_end.y > WIN_H)
		wolf->spr_end.y = WIN_H - 1;
	wolf->spr_width = abs((int)(WIN_H / TRANS_Y));
	wolf->spr_start.x = -wolf->spr_width / 2 + spr_scr_x;
	if (wolf->spr_start.x < 0)
		wolf->spr_start.x = 0;
	wolf->spr_end.x = wolf->spr_width / 2 + spr_scr_x;
	if (wolf->spr_end.x > WIN_W)
		wolf->spr_end.x = WIN_W - 1;
	return (spr_scr_x);
}

void		draw_sprite(t_wolf *wolf, int stripe, int i)
{
	t_color	color;
	int		y;
	int		d;

	y = wolf->spr_start.y;
	while (y < wolf->spr_end.y)
	{
		d = (y) * 256 - WIN_H * 128 + wolf->spr_height * 128;
		wolf->text_y = ((d * 128) / wolf->spr_height) / 256;
		if (OBJECT(i).data[wolf->text_x * OBJECT(i).bpp +
				wolf->text_y * OBJECT(i).sl + 3] == 0)
		{
			color.b = OBJECT(i).data[wolf->text_x *
				OBJECT(i).bpp + wolf->text_y * OBJECT(i).sl];
			color.g = OBJECT(i).data[wolf->text_x *
				OBJECT(i).bpp + wolf->text_y * OBJECT(i).sl + 1];
			color.r = OBJECT(i).data[wolf->text_x *
				OBJECT(i).bpp + wolf->text_y * OBJECT(i).sl + 2];
			color.alpha = 0;
			ft_putpixel(stripe, y, color, wolf->image);
		}
		y++;
	}
}

void		cast_sprites(t_wolf *wolf)
{
	int		i;
	int		spr_scr_x;
	int		stripe;

	i = 0;
	while (i < N_SPRITES)
	{
		spr_scr_x = sprite_position(wolf, i);
		stripe = wolf->spr_start.x;
		while (stripe < wolf->spr_end.x)
		{
			wolf->text_x = (256 * (stripe - (-wolf->spr_width / 2 + spr_scr_x))
					* TEXT_WIDTH / wolf->spr_width) / 256;
			if (TRANS_Y > 0 && stripe > 0 && stripe < WIN_W && TRANS_Y <
					wolf->z_buffer[stripe])
				draw_sprite(wolf, stripe, i);
			stripe++;
		}
		i++;
	}
}
