/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:20:13 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:11:42 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "./libft/libft.h"
# include "./minilibx_macos/mlx.h"

# define WIDTH 700
# define HEIGHT 500
# define PI 3.14159265359

typedef struct		s_mlx
{
	void			*init;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				size;
	int				endian;
}					t_mlx;

typedef struct		s_all
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planx;
	double			plany;
	double			move;
	double			rot;
	double			sky;
	double			cam;
	double			r_posx;
	double			r_posy;
	double			r_dirx;
	double			r_diry;
	int				mapx;
	int				mapy;
	double			s_distx;
	double			s_disty;
	double			d_distx;
	double			d_disty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				line_h;
	int				d_start;
	int				d_end;
	double			o_dirx;
	double			o_diry;
	double			o_planex;
	double			o_planey;
	double			wallx;
	int				texx;
	int				texy;
	double			flr_xwall;
	double			flr_ywall;
	double			d_wall;
	double			d_player;
	double			cur_dist;
	double			cur_floorx;
	double			cur_floory;
	double			weight;
	int				flr_texx;
	int				flr_texy;
	int				bonus;
}					t_all;

typedef struct		s_list
{
	char			*path;
	void			*tex_img;
	char			*data;
	char			num;
	int				bpp;
	int				size;
	int				endian;
	struct s_list	*next;
}					t_list;

typedef struct		s_bonus
{
	char			*path;
	void			*tex_img;
	char			*data;
	int				bpp;
	int				size;
	int				endian;
}					t_bonus;

typedef struct		s_env
{
	char			**map;
	t_mlx			mlx;
	t_all			a;
	t_bonus			wp;
	t_bonus			skybox;
	t_list			*list;
}					t_env;

void				wolf_algo(t_env *e);
void				free_map(t_env *e);
void				add_wall_texture(t_env *e, int x);
void				add_floor_texture(t_env *e, int x);
void				draw_wall_color(t_env *e, int x);
void				draw_wall_tex(t_env *e, int x);
int					key_hook(int keycode, t_env *e);
void				draw_reload(t_env *e);
void				draw_floor_tex(t_env *e, int x);
void				create_map(t_env *e);
void				create_map2(t_env *e);
void				load_texture(t_env *e);
void				draw_skybox(t_env *e, int x);
void				translate(int keycode, t_env *e);
void				rotate(int keycode, t_env *e);

#endif
