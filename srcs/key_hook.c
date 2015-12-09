/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 17:47:33 by tauvray           #+#    #+#             */
/*   Updated: 2015/06/10 18:27:38 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				key_press2(int keycode, t_env *e)
{
	if (keycode == 2)
		e->right = 1;
	if (keycode == 1)
		e->down = 1;
	if (keycode == 257)
		e->sprint = e->sprint * 10;
	if (keycode == 18)
		e->gun = 0;
	if (keycode == 19)
		e->gun = 1;
	if (keycode == 20)
		e->gun = 2;
	if (keycode == 49)
	{
		e->w = (WIDTH / 2) - (128 / 2);
		e->h = (HEIGHT) - 128;
	}
	return (0);
}

int				key_press(int keycode, t_env *e)
{
	if (keycode == 53)
		destroy_img(e);
	if (keycode == 48)
	{
		e->up = 0;
		e->left = 0;
		e->qwerty = (e->qwerty == 1) ? 0 : 1;
	}
	if (e->qwerty == 1)
	{
		if (keycode == 13)
			e->up = 1;
		if (keycode == 0)
			e->left = 1;
	}
	else
	{
		if (keycode == 6)
			e->up = 1;
		if (keycode == 12)
			e->left = 1;
	}
	key_press2(keycode, e);
	return (0);
}

int				key_release2(int keycode, t_env *e)
{
	if (keycode == 257)
		e->sprint = e->sprint / 10;
	return (0);
}

int				key_release(int keycode, t_env *e)
{
	if (e->qwerty == 1)
	{
		if (keycode == 13)
			e->up = 0;
		if (keycode == 0)
			e->left = 0;
	}
	else
	{
		if (keycode == 6)
			e->up = 0;
		if (keycode == 12)
			e->left = 0;
	}
	if (keycode == 2)
		e->right = 0;
	if (keycode == 1)
		e->down = 0;
	if (keycode == 49)
	{
		e->w = -100;
		e->h = -100;
	}
	key_release2(keycode, e);
	return (0);
}
