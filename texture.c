/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:20:13 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:11:42 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		floor_tex(t_env *e, int y)
{
	e->a.cur_dist = HEIGHT / (2.0 * y - HEIGHT);
	e->a.weight = (e->a.cur_dist - e->a.d_player)
	/ (e->a.d_wall - e->a.d_player);
	e->a.cur_floorx = e->a.weight * e->a.flr_xwall
	+ (1.0 - e->a.weight) * e->a.posx;
	e->a.cur_floory = e->a.weight * e->a.flr_ywall
	+ (1.0 - e->a.weight) * e->a.posy;
	e->a.flr_texx = (int)(e->a.cur_floorx * 64) % 64;
	e->a.flr_texy = (int)(e->a.cur_floory * 64) % 64;
}

void			draw_floor_tex(t_env *e, int x)
{
	int		y;
	int		pos;
	int		pos2;
	t_list	*save_pos;

	y = e->a.d_end;
	save_pos = e->list;
	while (y < HEIGHT)
	{
		floor_tex(e, y);
		while (e->list->num != 'd')
			e->list = e->list->next;
		pos = (int)(x * 4 + y * e->mlx.size);
		pos2 = (int)(e->a.flr_texx * 4 + e->a.flr_texy * e->list->size);
		e->mlx.data[pos + 2] = e->list->data[(int)pos2 + 2];
		e->mlx.data[pos + 1] = e->list->data[(int)pos2 + 1];
		e->mlx.data[pos] = e->list->data[(int)pos2];
		e->list = save_pos;
		y++;
	}
}

static void		wall_tex(t_env *e, int x, int y)
{
	int pos;
	int pos2;

	pos = (int)(x * 4 + y * e->mlx.size);
	while (e->map[(int)e->a.mapx][(int)e->a.mapy] != e->list->num)
		e->list = e->list->next;
	e->a.texy = (y * 2 - HEIGHT + e->a.line_h) * (64 / 2) / e->a.line_h;
	pos2 = (int)(e->a.texx * 4 + e->a.texy * e->list->size);
	e->mlx.data[pos + 2] = e->list->data[pos2 + 2];
	e->mlx.data[pos + 1] = e->list->data[pos2 + 1];
	e->mlx.data[pos] = e->list->data[pos2];
}

void			draw_wall_tex(t_env *e, int x)
{
	int		y;
	t_list	*save_pos;

	y = 0;
	save_pos = e->list;
	while (y < HEIGHT)
	{
		wall_tex(e, x, y);
		e->list = save_pos;
		y++;
	}
}

void			draw_skybox(t_env *e, int x)
{
	int x2;
	int y2;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		if (y <= e->a.d_start)
		{
			x2 = (3840 / (2.0 * PI)) * e->a.sky + x;
			y2 = (y / (HEIGHT / 2.0)) * 1528;
			e->mlx.data[(int)(x * 4 + y * e->mlx.size) + 2] =
				e->skybox.data[(int)(x2 * 4 + y2 * e->skybox.size) + 2];
			e->mlx.data[(int)(x * 4 + y * e->mlx.size) + 1] =
				e->skybox.data[(int)(x2 * 4 + y2 * e->skybox.size) + 1];
			e->mlx.data[(int)(x * 4 + y * e->mlx.size)] =
				e->skybox.data[(int)(x2 * 4 + y2 * e->skybox.size)];
		}
		y++;
	}
}
