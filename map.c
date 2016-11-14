/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:20:13 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:11:42 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	free_map(t_env *e)
{
	int	x;

	x = 0;
	while (x < 24)
	{
		free(e->map[x]);
		x++;
	}
	free(e->map);
}

void	create_map(t_env *e)
{
	e->map = (char **)malloc(sizeof(char *) * 24);
	e->map[0] = ft_strdup("abiaiiicccccciigggggffff");
	e->map[1] = ft_strdup("a0000000000000000000000f");
	e->map[2] = ft_strdup("b00bebb0b0b0000igg00000f");
	e->map[3] = ft_strdup("a000aaabaabab00i0a00000f");
	e->map[4] = ft_strdup("b000000ggi00hggg0a00000i");
	e->map[5] = ft_strdup("a00000000h0000000a00000i");
	e->map[6] = ft_strdup("b00fg0h00h0000000a00000h");
	e->map[7] = ft_strdup("a00000000h0000ghif00000h");
	e->map[8] = ft_strdup("b00f0h0i00000000iiffg00a");
	e->map[9] = ft_strdup("a0000000000000000000g00a");
	e->map[10] = ft_strdup("a0ab000000000000a00i000a");
	e->map[11] = ft_strdup("b0ba000ihhffaababf0i000a");
	e->map[12] = ft_strdup("a0ab0h0ababff000abai000a");
	e->map[13] = ft_strdup("a0ba0i00000000000a000f0a");
	e->map[14] = ft_strdup("b0ab0iifffffg0gg0000b00a");
	e->map[15] = ft_strdup("a00000000000g00000gaa00a");
	e->map[16] = ft_strdup("b00aaa0000b0aiicccicccii");
	e->map[17] = ft_strdup("a0000ihg00a0b0000000000g");
	e->map[18] = ft_strdup("a0000i0000b0a00000hhh00g");
	e->map[19] = ft_strdup("a0aaahg000a0000h00h0000g");
	e->map[20] = ft_strdup("a0a0000000b0000hh000h00g");
	e->map[21] = ft_strdup("a0baaiff00a0b000i000h00g");
	e->map[22] = ft_strdup("a00000000aa0ai000000000e");
	e->map[23] = ft_strdup("aaaaaaaaaaaaaiiiicccchhg");
}

void	create_map2(t_env *e)
{
	e->map = (char **)malloc(sizeof(char *) * 24);
	e->map[0] = ft_strdup("abiaiiicccccciigggggffff");
	e->map[1] = ft_strdup("a0000000000000000000000f");
	e->map[2] = ft_strdup("b000a0b0b0b0000igg00000f");
	e->map[3] = ft_strdup("a000aaabaabab00i0a00000f");
	e->map[4] = ft_strdup("b000000ggi00hggg0a00000i");
	e->map[5] = ft_strdup("a00000000h0000000a00000i");
	e->map[6] = ft_strdup("b00fg0h00h0000000a00000h");
	e->map[7] = ft_strdup("a00000000h0000ghif00000h");
	e->map[8] = ft_strdup("b00f0h0i00000000iiffg00a");
	e->map[9] = ft_strdup("a0000000000000000000g00a");
	e->map[10] = ft_strdup("a0ab000000000000a00i000a");
	e->map[11] = ft_strdup("b0ba000ihhffaababf0i000a");
	e->map[12] = ft_strdup("a0ab0h0ababff000abai000a");
	e->map[13] = ft_strdup("a0ba0i00000000000a000f0a");
	e->map[14] = ft_strdup("b0ab0iifffffg0gg0000b00a");
	e->map[15] = ft_strdup("a00000000000g00000gaa00a");
	e->map[16] = ft_strdup("b00aaa0000b0aiicccicccii");
	e->map[17] = ft_strdup("a0000ihg000000000000000g");
	e->map[18] = ft_strdup("a0000i000000000000hhh00g");
	e->map[19] = ft_strdup("a0aaahg00000000h00h0000g");
	e->map[20] = ft_strdup("a0a000000000000hh000h00g");
	e->map[21] = ft_strdup("a0baaiff00000000i000h00g");
	e->map[22] = ft_strdup("a00000000aa00i000000000g");
	e->map[23] = ft_strdup("aaaaaaaaaaaaaiiiicccchhg");
}
