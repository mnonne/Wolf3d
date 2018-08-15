/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_llops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:47:10 by aminadzh          #+#    #+#             */
/*   Updated: 2018/06/03 14:58:48 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		move_r(t_wolf *wolf)
{
	t_vec	right_dir;

	right_dir.x = DIR.x * cos(RAD(-90)) - DIR.y * sin(RAD(-90));
	right_dir.y = DIR.x * sin(RAD(-90)) + DIR.y * cos(RAD(-90));
	if ((int)(PLAYER.x + right_dir.x * MOVE_SPEED) > 0 &&
			(int)(PLAYER.x + right_dir.x * MOVE_SPEED) < MAP->height - 1
		&& ARRAY[(int)(PLAYER.x + right_dir.x * 0.5)][(int)PLAYER.y] == 0)
		PLAYER.x += right_dir.x * MOVE_SPEED;
	if ((int)(PLAYER.y + right_dir.y * MOVE_SPEED) > 0 &&
			(int)(PLAYER.y + right_dir.y * MOVE_SPEED) < MAP->height - 1
		&& ARRAY[(int)PLAYER.x][(int)(PLAYER.y + right_dir.y * 0.5)] == 0)
		PLAYER.y += right_dir.y * MOVE_SPEED;
}

void		run(t_wolf *wolf)
{
	if (wolf->actions.run)
	{
		MAP->move_speed = 0.06;
		wolf->walk_time += wolf->frame_time;
		if (wolf->walk_time >= 0.25)
			wolf->walk_time = 0;
		if (wolf->walk_time == 0 && wolf->actions.walk)
			system("afplay ./sounds/walk_2.wav&");
	}
}

void		walk(t_wolf *wolf)
{
	if (!wolf->actions.run)
	{
		MAP->move_speed = 0.03;
		wolf->walk_time += wolf->frame_time;
		if (wolf->walk_time >= 0.5)
			wolf->walk_time = 0;
		if (wolf->walk_time == 0 && wolf->actions.walk)
			system("afplay ./sounds/walk_2.wav&");
	}
}

void		shoot(t_wolf *wolf)
{
	wolf->shoot_time += wolf->frame_time;
	system("afplay ./sounds/gunshot.wav&");
	if (wolf->shoot_time > 0 && wolf->shoot_time < 0.15)
		wolf->shoot_texture = 1;
	else
		wolf->shoot_texture = 2;
	if (wolf->shoot_time >= 0.3)
		wolf->shoot_time = 0;
}

int			key_loop(t_wolf *wolf)
{
	if (wolf->actions.move_f)
		move_f(wolf);
	if (wolf->actions.rotate_l)
		rotate_l(wolf);
	if (wolf->actions.rotate_r)
		rotate_r(wolf);
	if (wolf->actions.move_b)
		move_b(wolf);
	if (wolf->actions.run)
		run(wolf);
	if (!wolf->actions.run)
		walk(wolf);
	if (wolf->actions.move_l)
		move_l(wolf);
	if (wolf->actions.move_r)
		move_r(wolf);
	if (wolf->actions.shoot)
		shoot(wolf);
	ft_clear_image(wolf);
	render(wolf);
	if (wolf->show_map)
		minimap(wolf);
	return (0);
}
