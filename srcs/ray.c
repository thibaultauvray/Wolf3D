/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 13:54:22 by tauvray           #+#    #+#             */
/*   Updated: 2015/06/10 18:29:31 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_loop(int x, t_env *e)
{
	e->p.camerax = 2 * x / (double)(WIDTH) - 1;
	e->p.side = 0;
	e->p.rayposx = e->p.posx;
	e->p.rayposy = e->p.posy;
	e->p.raydirx = e->p.dirx + e->p.planex * e->p.camerax;
	e->p.raydiry = e->p.diry + e->p.planey * e->p.camerax;
	e->p.mapx = (int)e->p.rayposx;
	e->p.mapy = (int)e->p.rayposy;
	e->p.deltadistx = sqrt(1 + (e->p.raydiry * e->p.raydiry) /
			(e->p.raydirx * e->p.raydirx));
	e->p.deltadisty = sqrt(1 + (e->p.raydirx * e->p.raydirx) /
			(e->p.raydiry * e->p.raydiry));
	e->p.hit = 0;
}

void		ray_step(t_env *e)
{
	if (e->p.raydirx < 0)
	{
		e->p.stepx = -1;
		e->p.sidedistx = (e->p.rayposx - e->p.mapx) * e->p.deltadistx;
	}
	else
	{
		e->p.stepx = 1;
		e->p.sidedistx = (e->p.mapx + 1.0 - e->p.rayposx) * e->p.deltadistx;
	}
	if (e->p.raydiry < 0)
	{
		e->p.stepy = -1;
		e->p.sidedisty = (e->p.rayposy - e->p.mapy) * e->p.deltadisty;
	}
	else
	{
		e->p.stepy = 1;
		e->p.sidedisty = (e->p.mapy + 1.0 - e->p.rayposy) * e->p.deltadisty;
	}
}

void		detect_wall(t_env *e)
{
	if (e->p.sidedistx < e->p.sidedisty)
	{
		e->p.sidedistx += e->p.deltadistx;
		e->p.mapx += e->p.stepx;
		e->p.side = 0;
	}
	else
	{
		e->p.sidedisty += e->p.deltadisty;
		e->p.mapy += e->p.stepy;
		e->p.side = 1;
	}
	if (e->map[e->p.mapx][e->p.mapy] != '0')
		e->p.hit = 1;
}

void		distance_wall(t_env *e)
{
	if (e->p.side == 0)
	{
		e->p.perpwalldist = fabs((e->p.mapx - e->p.rayposx + (1 - e->p.stepx)
					/ 2) / e->p.raydirx);
	}
	else
	{
		e->p.perpwalldist = fabs((e->p.mapy - e->p.rayposy + (1 - e->p.stepy)
					/ 2) / e->p.raydiry);
	}
	e->p.lineheight = abs((int)(HEIGHT / e->p.perpwalldist));
	e->p.drawstart = (e->p.lineheight * -1) / 2 + HEIGHT / 2;
	if (e->p.drawstart < 0)
		e->p.drawstart = 0;
	e->p.drawend = e->p.lineheight / 2 + HEIGHT / 2;
	if (e->p.drawend >= HEIGHT)
		e->p.drawend = HEIGHT - 1;
}

void		weapon(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->image[e->gun],
			(WIDTH / 2) - (e->width / 2), HEIGHT - 128);
}
