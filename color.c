/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:20:13 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:11:42 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		wall_color(t_env *e, int x, int y)
{
	if (y >= e->a.d_start && y <= e->a.d_end
				&& e->a.side == 0 && e->a.stepx == -1)
	{
		e->mlx.data[(int)(x * 4 + y * e->mlx.size) + 2] = 238;
		e->mlx.data[(int)(x * 4 + y * e->mlx.size) + 1] = 106;
		e->mlx.data[(int)(x * 4 + y * e->mlx.size)] = 80;
	}
	else if (y >= e->a.d_start && y <= e->a.d_end
				&& e->a.side == 1 && e->a.stepy == -1)
	{
		e->mlx.data[(int)(x * 4 + y * e->mlx.size) + 2] = 104;
		e->mlx.data[(int)(x * 4 + y * e->mlx.size) + 1] = 34;
		e->mlx.data[(int)(x * 4 + y * e->mlx.size)] = 139;
	}
	else if (y >= e->a.d_start && y <= e->a.d_end
				&& e->a.side == 0 && e->a.stepx == 1)
	{
		e->mlx.data[(int)(x * 4 + y * e->mlx.size) + 2] = 124;
		e->mlx.data[(int)(x * 4 + y * e->mlx.size) + 1] = 252;
		e->mlx.data[(int)(x * 4 + y * e->mlx.size)] = 0;
	}
}

static void		wall_color_2(t_env *e, int x, int y)
{
	if (y >= e->a.d_start && y <= e->a.d_end
				&& e->a.side == 1 && e->a.stepy == 1)
	{
		e->mlx.data[(int)(x * 4 + y * e->mlx.size) + 2] = 65;
		e->mlx.data[(int)(x * 4 + y * e->mlx.size) + 1] = 105;
		e->mlx.data[(int)(x * 4 + y * e->mlx.size)] = 225;
	}
	else if (y > e->a.d_end)
	{
		e->mlx.data[(int)(x * 4 + y * e->mlx.size) + 2] = 131;
		e->mlx.data[(int)(x * 4 + y * e->mlx.size) + 1] = 139;
		e->mlx.data[(int)(x * 4 + y * e->mlx.size)] = 139;
	}
	else if (y < e->a.d_start)
	{
		e->mlx.data[(int)(x * 4 + y * e->mlx.size) + 2] = 135;
		e->mlx.data[(int)(x * 4 + y * e->mlx.size) + 1] = 206;
		e->mlx.data[(int)(x * 4 + y * e->mlx.size)] = 235;
	}
}

void			draw_wall_color(t_env *e, int x)
{
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		wall_color(e, x, y);
		wall_color_2(e, x, y);
		y++;
	}
}
