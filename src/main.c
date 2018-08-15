/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 16:30:25 by aminadzh          #+#    #+#             */
/*   Updated: 2018/06/11 18:23:24 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			finish(char *message, int err_no)
{
	int		i;

	i = 0;
	ft_putendl(message);
	if (err_no == -1)
		ft_putendl("Incorrect player position");
	else if (err_no == -2)
		ft_putendl("Map is too small. Try 3 lines or more");
	else if (err_no == -3)
		ft_putendl("Maybe, try a perfect square map");
	else if (err_no == -4)
		ft_putendl("You should reconsider the map");
	exit(0);
}

int			escape(void)
{
	system("pkill -f afplay");
	exit(0);
}

int			get_floor_texture(t_texture *texture, int i, t_wolf *wolf)
{
	if (i == 4)
	{
		if (!(texture->ptr = mlx_xpm_file_to_image(MLX, FLOOR,
						&texture->wdth, &texture->height)))
			return (0);
	}
	else if (i == 5)
	{
		if (!(texture->ptr = mlx_xpm_file_to_image(MLX, CEIL_ONE,
						&texture->wdth, &texture->height)))
			return (0);
	}
	else
	{
		if (!(texture->ptr = mlx_xpm_file_to_image(MLX, CEIL_TWO,
						&texture->wdth, &texture->height)))
			return (0);
	}
	texture->data = mlx_get_data_addr(texture->ptr,
			&texture->bpp, &texture->sl, &texture->endian);
	texture->bpp /= 8;
	return (1);
}

int			get_wall_texture(t_texture *texture, int i, t_wolf *wolf)
{
	if (i == 0 && !(texture->ptr = mlx_xpm_file_to_image(MLX, WALL_ONE,
					&texture->wdth, &texture->height)))
		return (0);
	if (i == 1 && !(texture->ptr = mlx_xpm_file_to_image(MLX, WALL_TWO,
					&texture->wdth, &texture->height)))
		return (0);
	if (i == 2 && !(texture->ptr = mlx_xpm_file_to_image(MLX, WALL_THREE,
					&texture->wdth, &texture->height)))
		return (0);
	if (i == 3 && !(texture->ptr = mlx_xpm_file_to_image(MLX, WALL_FOUR,
					&texture->wdth, &texture->height)))
		return (0);
	texture->data = mlx_get_data_addr(texture->ptr,
			&texture->bpp, &texture->sl, &texture->endian);
	texture->bpp /= 8;
	return (1);
}

int			main(int ac, char **av)
{
	t_wolf	*wolf;
	int		err_no;

	err_no = 0;
	if (ac != 2)
		exit(finish("Usage: wolf3d [map]", 0));
	if (!(wolf = (t_wolf *)malloc(sizeof(t_wolf))))
		exit(finish("Unable to init", 0));
	if (!(wolf->map = (t_map *)malloc(sizeof(t_map))))
		exit(finish("Unable to create map", 0));
	if ((read_map(av[1], wolf, &err_no)) < 1)
		exit(finish("Invalid map", err_no));
	if (!(wolf->image = (t_image *)malloc(sizeof(t_image))))
		exit(0);
	if (!init_wolf(&wolf))
		exit(finish("Something is missing", 0));
	render(wolf);
	mlx_hook((WIN), 2, 0, key_press, wolf);
	mlx_hook((WIN), 3, 0, key_release, wolf);
	mlx_loop_hook((MLX), key_loop, wolf);
	mlx_hook(WIN, 17, 1L << 17, exit_x, NULL);
	system("afplay ./sounds/terminator.mp3&");
	wolf->music = 1;
	mlx_loop(wolf->mlx);
	return (0);
}
