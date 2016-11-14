/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:20:13 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:11:42 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		init_wolf_algo(t_env *e, int x)
{
	e->a.cam = 2.0 * x / (double)WIDTH - 1.0;
	e->a.r_posx = e->a.posx;
	e->a.r_posy = e->a.posy;
	e->a.r_dirx = (e->a.dirx + e->a.planx * e->a.cam);
	e->a.r_diry = (e->a.diry + e->a.plany * e->a.cam);
	e->a.mapx = (int)e->a.r_posx;
	e->a.mapy = (int)e->a.r_posy;
	e->a.d_distx = sqrt(1.0 + (e->a.r_diry * e->a.r_diry)
		/ (e->a.r_dirx * e->a.r_dirx));
	e->a.d_disty = sqrt(1.0 + (e->a.r_dirx * e->a.r_dirx)
		/ (e->a.r_diry * e->a.r_diry));
	e->a.hit = 0;
}

static void		casting(t_env *e)
{
	if (e->a.r_dirx < 0)
	{
		e->a.stepx = -1.0;
		e->a.s_distx = (e->a.r_posx - e->a.mapx) * e->a.d_distx;
	}
	else
	{
		e->a.stepx = 1.0;
		e->a.s_distx = (e->a.mapx + 1.0 - e->a.r_posx) * e->a.d_distx;
	}
	if (e->a.r_diry < 0)
	{
		e->a.stepy = -1.0;
		e->a.s_disty = (e->a.r_posy - e->a.mapy) * e->a.d_disty;
	}
	else
	{
		e->a.stepy = 1.0;
		e->a.s_disty = (e->a.mapy + 1.0 - e->a.r_posy) * e->a.d_disty;
	}
}

static void		hit(t_env *e)
{
	while (e->a.hit == 0)
	{
		if (e->a.s_distx < e->a.s_disty)
		{
			e->a.s_distx += e->a.d_distx;
			e->a.mapx += e->a.stepx;
			e->a.side = 0;
		}
		else
		{
			e->a.s_disty += e->a.d_disty;
			e->a.mapy += e->a.stepy;
			e->a.side = 1.0;
		}
		if (e->map[e->a.mapx][e->a.mapy] != '0')
			e->a.hit = 1.0;
	}
}

static void		height_of_wall(t_env *e)
{
	if (e->a.side == 0)
		e->a.perpwalldist = (e->a.mapx - e->a.r_posx
			+ (1.0 - e->a.stepx) / 2.0) / e->a.r_dirx;
	else
		e->a.perpwalldist = (e->a.mapy - e->a.r_posy
			+ (1.0 - e->a.stepy) / 2.0) / e->a.r_diry;
	e->a.line_h = (int)(HEIGHT / e->a.perpwalldist);
	e->a.d_start = -e->a.line_h / 2.0 + HEIGHT / 2.0;
	if (e->a.d_start < 0)
		e->a.d_start = 0.0;
	e->a.d_end = e->a.line_h / 2.0 + HEIGHT / 2.0;
	if (e->a.d_end >= HEIGHT)
		e->a.d_end = HEIGHT - 1.0;
}

void			wolf_algo(t_env *e)
{
	int x;

	x = 0;
	while (x < WIDTH)
	{
		init_wolf_algo(e, x);
		casting(e);
		hit(e);
		height_of_wall(e);
		if (e->a.bonus == 0)
			draw_wall_color(e, x);
		if (e->a.bonus == 1)
		{
			add_wall_texture(e, x);
			add_floor_texture(e, x);
			draw_skybox(e, x);
		}
		x++;
	}
}
