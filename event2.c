/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:20:13 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:11:42 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			translate(int keycode, t_env *e)
{
	if (keycode == 13)
	{
		if (e->map[(int)(e->a.posx + e->a.dirx * e->a.move)][(int)e->a.posy]
			== '0')
			e->a.posx += e->a.dirx * e->a.move;
		if (e->map[(int)e->a.posx][(int)(e->a.posy + e->a.diry * e->a.move)]
			== '0')
			e->a.posy += e->a.diry * e->a.move;
	}
	if (keycode == 1)
	{
		if (e->map[(int)(e->a.posx - e->a.dirx * e->a.move)][(int)e->a.posy]
			== '0')
			e->a.posx -= e->a.dirx * e->a.move;
		if (e->map[(int)e->a.posx][(int)(e->a.posy - e->a.diry * e->a.move)]
			== '0')
			e->a.posy -= e->a.diry * e->a.move;
	}
}

static void		rotate2(int keycode, t_env *e)
{
	if (keycode == 0)
	{
		e->a.sky -= 0.1;
		if (e->a.sky < 0.1)
			e->a.sky = (2 * PI);
		e->a.o_dirx = e->a.dirx;
		e->a.dirx = e->a.dirx * cos(e->a.rot) - e->a.diry * sin(e->a.rot);
		e->a.diry = e->a.o_dirx * sin(e->a.rot) + e->a.diry * cos(e->a.rot);
		e->a.o_planex = e->a.planx;
		e->a.planx = e->a.planx * cos(e->a.rot) - e->a.plany * sin(e->a.rot);
		e->a.plany = e->a.o_planex * sin(e->a.rot)
						+ e->a.plany * cos(e->a.rot);
	}
}

void			rotate(int keycode, t_env *e)
{
	if (keycode == 2)
	{
		e->a.sky += 0.1;
		if (e->a.sky > (2 * PI))
			e->a.sky = 0.1;
		e->a.o_dirx = e->a.dirx;
		e->a.dirx = e->a.dirx * cos(-e->a.rot)
					- e->a.diry * sin(-e->a.rot);
		e->a.diry = e->a.o_dirx * sin(-e->a.rot) + e->a.diry * cos(-e->a.rot);
		e->a.o_planex = e->a.planx;
		e->a.planx = e->a.planx * cos(-e->a.rot) - e->a.plany * sin(-e->a.rot);
		e->a.plany = e->a.o_planex * sin(-e->a.rot)
					+ e->a.plany * cos(-e->a.rot);
	}
	rotate2(keycode, e);
}
