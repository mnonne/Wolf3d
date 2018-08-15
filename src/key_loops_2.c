/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_loops_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 19:54:56 by aminadzh          #+#    #+#             */
/*   Updated: 2018/05/28 19:59:01 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		rotate_l(t_wolf *wolf)
{
	double	old_dir;
	double	old_plane;

	old_dir = DIR.x;
	old_plane = PLANE.x;
	DIR.x = DIR.x * cos(RAD(ROT_SPEED)) - DIR.y * sin(RAD(ROT_SPEED));
	DIR.y = old_dir * sin(RAD(ROT_SPEED)) + DIR.y * cos(RAD(ROT_SPEED));
	PLANE.x = PLANE.x * cos(RAD(ROT_SPEED)) - PLANE.y * sin(RAD(ROT_SPEED));
	PLANE.y = old_plane * sin(RAD(ROT_SPEED)) + PLANE.y * cos(RAD(ROT_SPEED));
}

void		rotate_r(t_wolf *wolf)
{
	double	old_dir;
	double	old_plane;

	old_dir = DIR.x;
	old_plane = PLANE.x;
	DIR.x = DIR.x * cos(RAD(-ROT_SPEED)) - DIR.y * sin(RAD(-ROT_SPEED));
	DIR.y = old_dir * sin(RAD(-ROT_SPEED)) + DIR.y * cos(RAD(-ROT_SPEED));
	PLANE.x = PLANE.x * cos(RAD(-ROT_SPEED)) - PLANE.y * sin(RAD(-ROT_SPEED));
	PLANE.y = old_plane * sin(RAD(-ROT_SPEED)) + PLANE.y * cos(RAD(-ROT_SPEED));
}

void		move_f(t_wolf *wolf)
{
	if ((int)(PLAYER.x + DIR.x * MOVE_SPEED) > 0 && (int)(PLAYER.x +
				DIR.x * MOVE_SPEED) < MAP->height - 1 &&
		ARRAY[(int)(PLAYER.x + DIR.x * 0.5)][(int)PLAYER.y] == 0)
		PLAYER.x += DIR.x * MOVE_SPEED;
	if ((int)(PLAYER.y + DIR.y * MOVE_SPEED) > 0 && (int)(PLAYER.y +
				DIR.y * MOVE_SPEED) < MAP->height - 1 &&
		ARRAY[(int)PLAYER.x][(int)(PLAYER.y + DIR.y * 0.5)] == 0)
		PLAYER.y += DIR.y * MOVE_SPEED;
}

void		move_b(t_wolf *wolf)
{
	if ((int)(PLAYER.x + DIR.x * -0.5) > 0 &&
		(int)(PLAYER.x + DIR.x * -MOVE_SPEED) < MAP->height - 1
		&& ARRAY[(int)(PLAYER.x + DIR.x * -0.5)][(int)PLAYER.y] == 0)
		PLAYER.x += DIR.x * -MOVE_SPEED;
	if ((int)(PLAYER.y + DIR.y * -0.5) > 0 &&
		(int)(PLAYER.y + DIR.y * -MOVE_SPEED) < MAP->height - 1
		&& ARRAY[(int)PLAYER.x][(int)(PLAYER.y + DIR.y * -0.5)] == 0)
		PLAYER.y += DIR.y * -MOVE_SPEED;
}

void		move_l(t_wolf *wolf)
{
	t_vec	left_dir;

	left_dir.x = DIR.x * cos(RAD(90)) - DIR.y * sin(RAD(90));
	left_dir.y = DIR.x * sin(RAD(90)) + DIR.y * cos(RAD(90));
	if ((int)(PLAYER.x + left_dir.x * MOVE_SPEED) > 0 &&
		(int)(PLAYER.x + left_dir.x * MOVE_SPEED) < MAP->height - 1
		&& ARRAY[(int)(PLAYER.x + left_dir.x * 0.5)][(int)PLAYER.y] == 0)
		PLAYER.x += left_dir.x * MOVE_SPEED;
	if ((int)(PLAYER.y + left_dir.y * MOVE_SPEED) > 0 &&
		(int)(PLAYER.y + left_dir.y * MOVE_SPEED) < MAP->height - 1
		&& ARRAY[(int)PLAYER.x][(int)(PLAYER.y + left_dir.y * 0.5)] == 0)
		PLAYER.y += left_dir.y * MOVE_SPEED;
}
