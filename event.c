/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:20:13 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:11:42 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		new_map(t_env *e)
{
	free_map(e);
	e->a.posx = 22.5;
	e->a.posy = 11.5;
	e->a.dirx = -1.0;
	e->a.diry = 0.0;
	e->a.planx = 0.0;
	e->a.plany = 0.66;
}

static void		teleport(int keycode, t_env *e)
{
	if (keycode == 49 && e->a.posx >= 22 && e->a.posx < 23
		&& e->a.posy >= 22.3 && e->a.posy < 23)
	{
		e->a.posx = 1.5;
		e->a.posy = 4.5;
	}
	else if (keycode == 49 && e->a.posx >= 1.3 && e->a.posx < 2
			&& e->a.posy >= 4 && e->a.posy < 5)
	{
		e->a.posx = 22.5;
		e->a.posy = 22.5;
	}
}

int				key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 8)
	{
		new_map(e);
		create_map2(e);
	}
	if (keycode == 7)
	{
		new_map(e);
		create_map(e);
	}
	if (keycode == 24 && e->a.bonus < 1)
		e->a.bonus += 1;
	if (keycode == 27 && e->a.bonus > 0)
		e->a.bonus -= 1;
	translate(keycode, e);
	rotate(keycode, e);
	teleport(keycode, e);
	draw_reload(e);
	return (0);
}
