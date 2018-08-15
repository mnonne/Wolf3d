/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 17:51:07 by aminadzh          #+#    #+#             */
/*   Updated: 2018/05/30 18:10:49 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

double		dist_to_wall(int *side, t_wolf *wolf)
{
	t_dda	dda;
	t_point	step;
	double	wall_dist;

	dda.delta.x = fabs(1 / RAY.x);
	dda.delta.y = fabs(1 / RAY.y);
	step = prepare_dda(RAY, &dda, wolf);
	*side = perform_dda(&dda, step, wolf);
	if (*side == 0)
		wall_dist = ((double)wolf->map_x - PLAYER.x +
				(double)(1 - step.x) / 2) / RAY.x;
	else
		wall_dist = ((double)wolf->map_y - PLAYER.y +
				(double)(1 - step.y) / 2) / RAY.y;
	return (wall_dist);
}

void		count_time(t_wolf *wolf)
{
	wolf->old_time = (clock_t)wolf->time;
	wolf->time = clock();
	wolf->frame_time = (double)(wolf->time - wolf->old_time) / CLOCKS_PER_SEC;
	if (!wolf->actions.run)
		MAP->move_speed = wolf->frame_time * 1.2;
	else
		MAP->move_speed = wolf->frame_time * 2.4;
	MAP->rot_speed = wolf->frame_time * 70;
	wolf->ceil_time += wolf->frame_time;
	if (wolf->ceil_time > 0 && wolf->ceil_time < 2)
		wolf->ceil_text = 5;
	else
		wolf->ceil_text = 6;
	if (wolf->ceil_time >= 4)
		wolf->ceil_time = 0;
}

void		swap(double *a, double *b, int *x, int *y)
{
	double	c;
	int		z;

	c = *a;
	*a = *b;
	*b = c;
	z = *x;
	*x = *y;
	*y = z;
}

void		comb_sort(int *order, double *dist, int amount)
{
	int		i;
	int		j;
	int		swapped;

	i = 0;
	while (i < amount - 1)
	{
		swapped = 0;
		j = 0;
		while (j < amount - i - 1)
		{
			if (dist[j] < dist[j + 1])
			{
				swap(&dist[j], &dist[j + 1], &order[j], &order[j + 1]);
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
			break ;
		i++;
	}
}
