/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:20:13 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:11:42 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			add_wall_texture(t_env *e, int x)
{
	if (e->a.side == 1)
		e->a.wallx = e->a.r_posx + ((e->a.mapy - e->a.r_posy +
			(1 - e->a.stepy) / 2) / e->a.r_diry * e->a.r_dirx);
	else
		e->a.wallx = e->a.r_posy + ((e->a.mapx - e->a.r_posx +
			(1 - e->a.stepx) / 2) / e->a.r_dirx * e->a.r_diry);
	e->a.wallx -= (int)e->a.wallx;
	e->a.texx = (e->a.wallx * 64);
	if (e->a.side == 0 && e->a.r_dirx > 0)
		e->a.texx = 64 - e->a.texx - 1;
	if (e->a.side == 1 && e->a.r_diry < 0)
		e->a.texx = 64 - e->a.texx - 1;
	draw_wall_tex(e, x);
}

void			add_floor_texture(t_env *e, int x)
{
	if (e->a.side == 0 && e->a.r_dirx > 0)
	{
		e->a.flr_xwall = e->a.mapx;
		e->a.flr_ywall = e->a.mapy + e->a.wallx;
	}
	else if (e->a.side == 0 && e->a.r_dirx < 0)
	{
		e->a.flr_xwall = e->a.mapx + 1.0;
		e->a.flr_ywall = e->a.mapy + e->a.wallx;
	}
	else if (e->a.side == 1 && e->a.r_diry > 0)
	{
		e->a.flr_xwall = e->a.mapx + e->a.wallx;
		e->a.flr_ywall = e->a.mapy;
	}
	else
	{
		e->a.flr_xwall = e->a.mapx + e->a.wallx;
		e->a.flr_ywall = e->a.mapy + 1.0;
	}
	e->a.d_wall = e->a.perpwalldist;
	e->a.d_player = 0.0;
	if (e->a.d_end < 0)
		e->a.d_end = HEIGHT;
	draw_floor_tex(e, x);
}
