/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:20:13 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:11:42 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		red_cross(int keycode, t_env *e)
{
	(void)keycode;
	(void)e;
	exit(0);
	return (0);
}

void			draw_reload(t_env *e)
{
	mlx_destroy_image(e->mlx.init, e->mlx.img);
	e->mlx.img = mlx_new_image(e->mlx.init, WIDTH, HEIGHT);
	wolf_algo(e);
	mlx_put_image_to_window(e->mlx.init, e->mlx.win, e->mlx.img, 0, 0);
	if (e->a.bonus == 1)
		mlx_put_image_to_window(e->mlx.init, e->mlx.win,
			e->wp.tex_img, 222, 244);
}

static t_mlx	setup_mlx(void)
{
	t_mlx mlx;

	mlx.init = mlx_init();
	mlx.win = mlx_new_window(mlx.init, WIDTH, HEIGHT, "wolf3d");
	mlx.img = mlx_new_image(mlx.init, WIDTH, HEIGHT);
	mlx.data = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.size, &mlx.endian);
	return (mlx);
}

static void		init_env(t_env *e)
{
	e->a.posx = 22.5;
	e->a.posy = 11.5;
	e->a.dirx = -1.0;
	e->a.diry = 0.0;
	e->a.planx = 0.0;
	e->a.plany = 0.66;
	e->a.bonus = 0;
	e->a.move = 0.0045 * 20.0;
	e->a.rot = 0.0045 * 14.0;
	e->a.sky = 0;
	e->list = NULL;
	e->mlx = setup_mlx();
	create_map(e);
	load_texture(e);
}

int				main(void)
{
	t_env *e;

	e = (t_env *)malloc(sizeof(t_env));
	init_env(e);
	wolf_algo(e);
	mlx_put_image_to_window(e->mlx.init, e->mlx.win, e->mlx.img, 0, 0);
	mlx_hook(e->mlx.win, 2, 1, key_hook, e);
	mlx_hook(e->mlx.win, 17, (1L << 17), red_cross, e);
	mlx_loop(e->mlx.init);
	return (0);
}
