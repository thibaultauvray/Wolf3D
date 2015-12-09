/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 18:13:39 by tauvray           #+#    #+#             */
/*   Updated: 2015/06/04 15:46:21 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_uint32		swap_endian(t_uint32 in)
{
	t_uint32	out;

	out = (in << 24);
	out |= ((in << 8) & 0x00ff0000);
	out |= ((in >> 8) & 0x0000ff00);
	out |= (in >> 24);
	return (out);
}

t_uint32		true_color(void *mlx, int endian, int rgb)
{
	t_uint32	color;

	color = mlx_get_color_value(mlx, rgb);
	if (endian == MLX_BIG_ENDIAN)
		color = swap_endian(color);
	return (color);
}

void			pxl_to_img(t_env *e, int x, int y, int color)
{
	int		px;

	px = y * e->szl + x * (e->bpx / 8);
	e->edit[px] = color;
	e->edit[px + 1] = color >> 8;
	e->edit[px + 2] = color >> 16;
}
