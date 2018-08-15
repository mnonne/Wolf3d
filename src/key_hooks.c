/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:33:27 by aminadzh          #+#    #+#             */
/*   Updated: 2018/06/03 15:59:52 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		sounds(int k, t_wolf *wolf)
{
	if (k == 32 && !wolf->music)
	{
		wolf->music = 1;
		system("afplay ./sounds/terminator.mp3&");
	}
	if (k == 46 && wolf->music)
	{
		wolf->music = 0;
		system("pkill -f afplay");
	}
}

int			key_press(int k, t_wolf *wolf)
{
	if (k == 13)
		wolf->actions.move_f = 1;
	if (k == 1)
		wolf->actions.move_b = 1;
	if (k == 123)
		wolf->actions.rotate_l = 1;
	if (k == 124)
		wolf->actions.rotate_r = 1;
	if (k == 53)
		escape();
	if (k == 257)
		wolf->actions.run = 1;
	if (k == 0)
		wolf->actions.move_l = 1;
	if (k == 2)
		wolf->actions.move_r = 1;
	if (k == 49)
		wolf->actions.shoot = 1;
	if (k == 13 || k == 1 || k == 0 || k == 2)
		wolf->actions.walk = 1;
	if (k == 48)
		wolf->show_map = 1;
	sounds(k, wolf);
	return (0);
}

void		key_release_2(int k, t_wolf *wolf)
{
	if (k == 13 || k == 1 || k == 0 || k == 2)
	{
		wolf->walk_time = 0;
		wolf->actions.walk = 0;
	}
	if (k == 48)
		wolf->show_map = 0;
}

int			key_release(int k, t_wolf *wolf)
{
	if (k == 13)
		wolf->actions.move_f = 0;
	if (k == 1)
		wolf->actions.move_b = 0;
	if (k == 123)
		wolf->actions.rotate_l = 0;
	if (k == 124)
		wolf->actions.rotate_r = 0;
	if (k == 257)
		wolf->actions.run = 0;
	if (k == 0)
		wolf->actions.move_l = 0;
	if (k == 2)
		wolf->actions.move_r = 0;
	if (k == 49)
	{
		wolf->actions.shoot = 0;
		wolf->shoot_texture = 0;
	}
	key_release_2(k, wolf);
	return (0);
}

int			init_wolf_2(t_wolf **wolf)
{
	int		i;
	int		m_size;

	i = 0;
	while (i < (GUNS))
	{
		if (get_gun(&(*wolf)->gun[i], i, *wolf) == 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < OBJ_NUM)
	{
		if (get_object(&(*wolf)->object[i], i, *wolf) == 0)
			return (0);
		i++;
	}
	ft_create_image((*wolf)->image, *wolf, WIN_W, WIN_H);
	m_size = WIN_H / 3 / (*wolf)->map->height * (*wolf)->map->height;
	ft_create_image((*wolf)->minimap, *wolf, m_size, m_size);
	return (1);
}
