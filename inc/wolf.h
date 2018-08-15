/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 16:45:11 by aminadzh          #+#    #+#             */
/*   Updated: 2018/06/11 18:16:35 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "../libft/get_next_line.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <time.h>

# define WIN_H 720
# define WIN_W 980
# define UNIT 64
# define MAP wolf->map
# define ARRAY wolf->map->array
# define HEIGHT wolf->map->height
# define WIDTH map->width
# define IMAGE wolf->image
# define MLX wolf->mlx
# define RAD(x) ((x) * (M_PI / 180))
# define FOV RAD(60)
# define WIN wolf->win
# define PLAYER wolf->map->player_pos
# define MAP_W wolf->map->width
# define MAP_H wolf->map->height
# define CAMERA wolf->map->camera
# define DIR wolf->map->dir_vec
# define PLANE wolf->map->plane
# define ROT_SPEED wolf->map->rot_speed
# define MOVE_SPEED wolf->map->move_speed
# define RAY wolf->map->ray

# define TEXTURES 7
# define GUNS 3
# define OBJECTS wolf->obj_num
# define TEXT_WIDTH 128

# define WALL_ONE "./xpm_images/wall1.xpm"
# define WALL_TWO "./xpm_images/wall2.xpm"
# define WALL_THREE "./xpm_images/wall3.xpm"
# define WALL_FOUR "./xpm_images/wall4.xpm"
# define FLOOR "./xpm_images/floor2.xpm"
# define CEIL_ONE "./xpm_images/ceiling1.xpm"
# define CEIL_TWO "./xpm_images/ceiling2.xpm"
# define GUN_ONE "./xpm_images/gun_animation/gutling1.xpm"
# define GUN_TWO "./xpm_images/gun_animation/gutling2.xpm"
# define GUN_THREE "./xpm_images/gun_animation/gutling3.xpm"
# define BARREL "./xpm_images/barrel2.xpm"
# define CORPSE "./xpm_images/hanging_corpse.xpm"

# define WALL_TEXT(i) wolf->texture[i]
# define FLOOR_TEXT wolf->texture[4]
# define GUN_TEXT wolf->gun[wolf->shoot_texture]
# define WALL_DIST wolf->wall_dist

# define N_SPRITES wolf->map->num_sprites
# define SPRITE_ORDER wolf->map->sprite_order
# define SPRITE_DIST wolf->map->sprite_distance
# define SPRITE wolf->map->sprite
# define OBJ_NUM 2

# define SIDE_DIST_X dda->side_dist.x
# define SIDE_DIST_Y dda->side_dist.y
# define TRANS_X wolf->transform.x
# define TRANS_Y wolf->transform.y
# define SPR_POS_X wolf->sprite_pos.x
# define SPR_POS_Y wolf->sprite_pos.y
# define OBJECT(x) wolf->object[SPRITE[SPRITE_ORDER[x]].texture]
# define CT wolf->ceil_text
# define TEXT_X wolf->text_x
# define TEXT_Y wolf->text_y
# define COLOR wolf->color

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
	int			alpha;
}				t_color;

typedef struct	s_vec
{
	double		x;
	double		y;
}				t_vec;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_dda
{
	t_vec		side_dist;
	t_vec		delta;
}				t_dda;

typedef struct	s_line
{
	t_point		st_end;
	int			len;
}				t_line;

typedef struct	s_image
{
	void		*img;
	char		*data;
	int			bpp;
	int			sl;
	int			endian;
	int			height;
	int			width;
}				t_image;

typedef struct	s_texture
{
	void		*ptr;
	char		*data;
	int			bpp;
	int			sl;
	int			endian;
	int			height;
	int			wdth;
}				t_texture;

typedef struct	s_object
{
	int			id;
	double		x;
	double		y;
	int			texture;
}				t_object;

typedef struct	s_map
{
	int			width;
	int			height;
	int			**array;
	t_vec		player_pos;
	t_vec		dir_vec;
	t_vec		ray;
	double		rot_speed;
	double		move_speed;
	t_vec		plane;
	int			num_sprites;
	t_object	*sprite;
	int			*sprite_order;
	double		*sprite_distance;
}				t_map;

typedef struct	s_actions
{
	int			rotate_l;
	int			rotate_r;
	int			move_f;
	int			move_b;
	int			run;
	int			walk;
	int			move_l;
	int			move_r;
	int			shoot;
}				t_actions;

typedef struct	s_wolf
{
	t_image		*image;
	t_map		*map;
	void		*mlx;
	t_actions	actions;
	void		*win;
	t_texture	texture[TEXTURES];
	t_texture	gun[GUNS];
	t_texture	object[OBJ_NUM];
	clock_t		time;
	clock_t		old_time;
	double		frame_time;
	double		shoot_time;
	int			shoot_texture;
	int			start;
	int			end;
	int			line_len;
	double		wall_dist;
	int			text_x;
	int			text_y;
	int			map_x;
	int			map_y;
	double		camera;
	double		z_buffer[WIN_W];
	t_vec		sprite_pos;
	t_vec		transform;
	int			spr_height;
	int			spr_width;
	t_point		spr_start;
	t_point		spr_end;
	double		ceil_time;
	int			ceil_text;
	double		walk_time;
	int			music;
	t_image		*minimap;
	t_color		color;
	int			show_map;
}				t_wolf;

/*
** main.c
*/
int				finish(char *message, int err_no);
int				escape(void);
int				get_floor_texture(t_texture *texture, int i, t_wolf *wolf);
int				get_wall_texture(t_texture *texture, int i, t_wolf *wolf);

/*
** read_map.c
*/
int				count_lines(char *file);
int				*fill_map(char *line, t_wolf *wolf, int n);
int				check_line(int fd, t_wolf *wolf, int *err_no);
int				fill_objects(t_wolf *wolf, int *err_no);

/*
** image.c
*/
int				ft_create_image(t_image *image, t_wolf *wolf,
		int width, int height);
void			ft_clear_image(t_wolf *wolf);
void			ft_putpixel(int x, int y, t_color color, t_image *image);

/*
** render.c
*/
t_point			prepare_dda(t_vec ray, t_dda *dda, t_wolf *wolf);
int				perform_dda(t_dda *dda, t_point step, t_wolf *wolf);
void			order_objects(t_wolf *wolf);
void			render(t_wolf *wolf);

/*
** render_2.c
*/
double			dist_to_wall(int *side, t_wolf *wolf);
void			count_time(t_wolf *wolf);
void			swap(double *a, double *b, int *x, int *y);
void			comb_sort(int *order, double *dist, int amount);

/*
** key_hooks.c
*/
int				key_press(int k, t_wolf *wolf);
int				key_release(int k, t_wolf *wolf);
int				exit_x(void);
int				read_map(char *file, t_wolf *wolf, int *err_no);
int				init_wolf_2(t_wolf **wolf);

/*
** key_loops.c
*/
void			move_r(t_wolf *wolf);
void			run(t_wolf *wolf);
void			walk(t_wolf *wolf);
void			shoot(t_wolf *wolf);
int				sprite_position(t_wolf *wolf, int i);
int				key_loop(t_wolf *wolf);
/*
** key_loops_2.c
*/
void			rotate_l(t_wolf *wolf);
void			rotate_r(t_wolf *wolf);
void			move_f(t_wolf *wolf);
void			move_b(t_wolf *wolf);
void			move_l(t_wolf *wolf);

/*
** draw_lines.c
*/
void			draw_wall(int x, int side, t_wolf *wolf);
t_vec			prepare_surfaces(int side, double wall_x, t_wolf *wolf);
void			draw_floor(int x, t_vec floor, t_wolf *wolf);
void			draw_ceiling(int x, t_vec floor, t_wolf *wolf);
void			draw_column(int side, int x, t_wolf *wolf);

/*
** init.c
*/
int				init_wolf(t_wolf **wolf);
int				get_gun(t_texture *texture, int i, t_wolf *wolf);
int				get_object(t_texture *texture, int i, t_wolf *wolf);
void			set_object(t_wolf **wolf, int texture, int id, t_point p);
int				set_player(int x, int y, t_wolf *wolf);

/*
** obstacles.c
*/
int				sprite_position(t_wolf *wolf, int i);
void			draw_sprite(t_wolf *wolf, int stripe, int i);
void			cast_sprites(t_wolf *wolf);

/*
** minimap.c
*/
void			minimap(t_wolf *wolf);

#endif
