/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:20:13 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:11:42 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_list	*ft_create_elem(t_mlx mlx, char num, char *path)
{
	t_list	*list;
	int		tex_width;
	int		tex_height;

	list = (t_list *)malloc(sizeof(t_list));
	if (list)
	{
		list->path = ft_strdup(path);
		list->num = num;
		list->tex_img = mlx_xpm_file_to_image(mlx.init, path,
						&tex_width, &tex_height);
		if (!list->tex_img)
		{
			ft_putstr("Can not load texture\n");
			exit(0);
		}
		list->data = mlx_get_data_addr(list->tex_img, &list->bpp,
					&list->size, &list->endian);
		list->next = NULL;
	}
	return (list);
}

static void		ft_list_push_back(t_list **begin_list,
									t_mlx mlx, char num, char *path)
{
	t_list *list;

	list = *begin_list;
	if (!list)
		*begin_list = ft_create_elem(mlx, num, path);
	else
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(mlx, num, path);
	}
}

static t_bonus	load_weapon(t_mlx mlx, char *path)
{
	t_bonus	weap;
	int		tex_width;
	int		tex_height;

	weap.path = ft_strdup(path);
	weap.tex_img = mlx_xpm_file_to_image(mlx.init, path,
					&tex_width, &tex_height);
	if (!weap.tex_img)
	{
		ft_putstr("Can not load weapon\n");
		exit(0);
	}
	weap.data = mlx_get_data_addr(weap.tex_img, &weap.bpp,
				&weap.size, &weap.endian);
	return (weap);
}

static t_bonus	load_skybox(t_mlx mlx, char *path)
{
	t_bonus	skybox;
	int		tex_width;
	int		tex_height;

	skybox.path = ft_strdup(path);
	skybox.tex_img = mlx_xpm_file_to_image(mlx.init, path,
					&tex_width, &tex_height);
	if (!skybox.tex_img)
	{
		ft_putstr("Can not load skybox\n");
		exit(0);
	}
	skybox.data = mlx_get_data_addr(skybox.tex_img, &skybox.bpp,
				&skybox.size, &skybox.endian);
	return (skybox);
}

void			load_texture(t_env *e)
{
	e->wp = load_weapon(e->mlx, "texture/wepon3.xpm");
	e->skybox = load_skybox(e->mlx, "texture/greg.xpm");
	ft_list_push_back(&e->list, e->mlx, 'a', "texture/redbrick.xpm");
	ft_list_push_back(&e->list, e->mlx, 'b', "texture/eagle.xpm");
	ft_list_push_back(&e->list, e->mlx, 'c', "texture/eridu4.xpm");
	ft_list_push_back(&e->list, e->mlx, 'd', "texture/efloor.xpm");
	ft_list_push_back(&e->list, e->mlx, 'e', "texture/etoile.xpm");
	ft_list_push_back(&e->list, e->mlx, 'f', "texture/bluestone.xpm");
	ft_list_push_back(&e->list, e->mlx, 'g', "texture/mossy.xpm");
	ft_list_push_back(&e->list, e->mlx, 'h', "texture/purplestone.xpm");
	ft_list_push_back(&e->list, e->mlx, 'i', "texture/wood.xpm");
}
