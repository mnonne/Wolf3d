/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:47:06 by aminadzh          #+#    #+#             */
/*   Updated: 2018/06/11 18:21:43 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			ft_create_image(t_image *image, t_wolf *wolf, int width, int height)
{
	image->img = mlx_new_image(wolf->mlx, width, height);
	image->data = mlx_get_data_addr(image->img, &image->bpp, &image->sl,
			&image->endian);
	image->bpp /= 8;
	image->width = width;
	image->height = height;
	return (0);
}

void		ft_clear_image(t_wolf *wolf)
{
	int		i;

	i = ((wolf->image->width - 1) * wolf->image->bpp +
			(wolf->image->height - 1) * wolf->image->sl);
	ft_bzero(wolf->image->data, (size_t)i);
}

void		ft_putpixel(int x, int y, t_color color, t_image *image)
{
	int		i;

	i = x * image->bpp + y * image->sl;
	if (x >= 0 && x < image->width && y >= 0 && y < image->height &&
		i <= image->height * image->sl + image->width * 4)
	{
		image->data[i] = (char)color.b;
		image->data[i + 1] = (char)color.g;
		image->data[i + 2] = (char)color.r;
		image->data[i + 3] = (char)color.alpha;
	}
}

int			exit_x(void)
{
	system("pkill -f afplay");
	exit(0);
}
