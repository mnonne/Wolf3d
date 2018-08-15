/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 19:32:21 by aminadzh          #+#    #+#             */
/*   Updated: 2018/05/31 16:41:22 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			init_wolf(t_wolf **wolf)
{
	int		i;

	i = 0;
	(*wolf)->mlx = mlx_init();
	(*wolf)->win = mlx_new_window((*wolf)->mlx, (WIN_W), (WIN_H), "WOLF 3D");
	(*wolf)->time = 0;
	(*wolf)->shoot_texture = 0;
	while (i < 4)
	{
		if (get_wall_texture(&(*wolf)->texture[i], i, *wolf) == 0)
			return (0);
		i++;
	}
	while (i < TEXTURES)
	{
		if (get_floor_texture(&(*wolf)->texture[i], i, *wolf) == 0)
			return (0);
		i++;
	}
	if (!((*wolf)->minimap = (t_image *)malloc(sizeof(t_image))))
		return (0);
	return (init_wolf_2(wolf));
}

int			get_gun(t_texture *texture, int i, t_wolf *wolf)
{
	if (i == 0)
	{
		if (!(texture->ptr = mlx_xpm_file_to_image((MLX), (GUN_ONE),
						&texture->wdth, &texture->height)))
			return (0);
	}
	else if (i == 1)
	{
		if (!(texture->ptr = mlx_xpm_file_to_image((MLX), (GUN_TWO),
						&texture->wdth, &texture->height)))
			return (0);
	}
	else
	{
		if (!(texture->ptr = mlx_xpm_file_to_image((MLX), (GUN_THREE),
						&texture->wdth, &texture->height)))
			return (0);
	}
	texture->data = mlx_get_data_addr(texture->ptr,
			&texture->bpp, &texture->sl, &texture->endian);
	texture->bpp /= 8;
	return (1);
}

int			get_object(t_texture *texture, int i, t_wolf *wolf)
{
	if (i == 0)
	{
		if (!(texture->ptr = mlx_xpm_file_to_image((MLX), (BARREL),
						&texture->wdth, &texture->height)))
			return (0);
	}
	else if (i == 1)
	{
		if (!(texture->ptr = mlx_xpm_file_to_image((MLX), (CORPSE),
						&texture->wdth, &texture->height)))
			return (0);
	}
	texture->data = mlx_get_data_addr(texture->ptr,
			&texture->bpp, &texture->sl, &texture->endian);
	texture->bpp /= 8;
	return (1);
}

void		set_object(t_wolf **wolf, int texture, int id, t_point p)
{
	(*wolf)->map->sprite[id].id = id;
	(*wolf)->map->sprite[id].texture = texture - 2;
	(*wolf)->map->sprite[id].x = p.y + 0.5;
	(*wolf)->map->sprite[id].y = p.x + 0.5;
	if (texture == 3)
		(*wolf)->map->array[p.y][p.x] = 0;
}

int			set_player(int x, int y, t_wolf *wolf)
{
	if (y == HEIGHT - 1 || x == HEIGHT - 1)
		return (-1);
	PLAYER.y = x + 0.5;
	PLAYER.x = y + 0.5;
	DIR.x = -1;
	DIR.y = 0;
	PLANE.x = 0;
	PLANE.y = 0.66;
	ARRAY[y][x] = 0;
	return (0);
}
