/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 15:49:18 by tauvray           #+#    #+#             */
/*   Updated: 2015/06/10 16:38:58 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		draw_yi(int x, t_env *e)
{
	int		yi;
	t_rgb	c;

	yi = 0;
	while (yi < HEIGHT)
	{
		if (yi < e->p.drawstart)
			c.c = (0x00FFFF);
		else if (yi > e->p.drawend)
			c.c = (0x00FF00);
		else if (e->p.side == 0 && e->p.raydirx >= 0)
			c.c = (0xFD6C9E);
		else if (e->p.side == 0 && e->p.raydirx < 0)
			c.c = (0x00EFCF);
		else if (e->p.side == 1 && e->p.raydiry <= 0)
			c.c = (0xC15705);
		else
			c.c = (0xA222D9);
		if (e->map[e->p.mapx][e->p.mapy] == '2' && yi < e->p.drawend &&
				yi > e->p.drawstart)
			c.c = (0x28A55F);
		pxl_to_img(e, x, yi, c.c);
		yi++;
	}
}

void		ray_move(t_env *e)
{
	e->p.movespeed = 0.05 * e->sprint;
	e->p.rotspeed = 0.05;
	if (e->up == 1)
	{
		if (e->map[(int)(e->p.posx + e->p.dirx * e->p.movespeed)]
				[(int)(e->p.posy)] != '1')
		{
			e->p.posx += e->p.dirx * e->p.movespeed;
		}
		if (e->map[(int)(e->p.posx)]
				[(int)(e->p.posy + e->p.diry * e->p.movespeed)] != '1')
		{
			e->p.posy += e->p.diry * e->p.movespeed;
		}
	}
	if (e->down == 1)
	{
		if (e->map[(int)(e->p.posx - e->p.dirx * e->p.movespeed)]
				[(int)(e->p.posy)] != '1')
			e->p.posx -= e->p.dirx * e->p.movespeed;
		if (e->map[(int)(e->p.posx)]
				[(int)(e->p.posy - e->p.diry * e->p.movespeed)] != '1')
			e->p.posy -= e->p.diry * e->p.movespeed;
	}
}

void		ray_move2(t_env *e)
{
	if (e->left == 1)
	{
		e->p.olddirx = e->p.dirx;
		e->p.dirx = e->p.dirx * cos(e->p.rotspeed) - e->p.diry *
			sin(e->p.rotspeed);
		e->p.diry = e->p.olddirx * sin(e->p.rotspeed) + e->p.diry *
			cos(e->p.rotspeed);
		e->p.oldplanex = e->p.planex;
		e->p.planex = e->p.planex * cos(e->p.rotspeed) -
			e->p.planey * sin(e->p.rotspeed);
		e->p.planey = e->p.oldplanex * sin(e->p.rotspeed) +
			e->p.planey * cos(e->p.rotspeed);
	}
}

void		ray_move3(t_env *e)
{
	if (e->right == 1)
	{
		e->p.olddirx = e->p.dirx;
		e->p.dirx = e->p.dirx * cos((e->p.rotspeed * -1)) -
			e->p.diry * sin((e->p.rotspeed * -1));
		e->p.diry = e->p.olddirx * sin((e->p.rotspeed * -1)) +
			e->p.diry * cos((e->p.rotspeed * -1));
		e->p.oldplanex = e->p.planex;
		e->p.planex = e->p.planex * cos((e->p.rotspeed * -1)) -
			e->p.planey * sin((e->p.rotspeed * -1));
		e->p.planey = e->p.oldplanex * sin((e->p.rotspeed * -1)) +
			e->p.planey * cos((e->p.rotspeed * -1));
	}
}

void		draw_wolf(t_env *e)
{
	int x;

	x = 0;
	while (x < WIDTH)
	{
		init_loop(x, e);
		ray_step(e);
		while (e->p.hit == 0)
		{
			detect_wall(e);
		}
		distance_wall(e);
		draw_yi(x, e);
		x++;
	}
	ray_move(e);
	ray_move2(e);
	ray_move3(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_put_image_to_window(e->mlx, e->win, e->shot, e->w, e->h);
	weapon(e);
}
