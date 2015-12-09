/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 15:25:57 by tauvray           #+#    #+#             */
/*   Updated: 2015/06/10 18:26:15 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int					expose_hook(t_env *e)
{
	(void)e;
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int					loop_hook(t_env *e)
{
	(void)e;
	draw_wolf(e);
	return (0);
}

void				**fill_weapon(t_env *e)
{
	void	**weapon;
	int		i;

	i = 0;
	if (!(weapon = (void **)malloc(sizeof(void *) * 3)))
		return (NULL);
	weapon[0] = mlx_xpm_file_to_image(e->mlx, "img/gun1.xpm", &e->width,
			&e->height);
	weapon[1] = mlx_xpm_file_to_image(e->mlx, "img/gun2.xpm", &e->width,
			&e->height);
	weapon[2] = mlx_xpm_file_to_image(e->mlx, "img/gun3.xpm", &e->width,
			&e->height);
	return (weapon);
}

void				ft_init(void)
{
	t_env	e;

	if (!(e.mlx = mlx_init()))
		exit(1);
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "wolf3d");
	e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
	e.edit = mlx_get_data_addr(e.img, &(e.bpx), &(e.szl), &(e.endiant));
	e.map = strsplit_map();
	if (e.map == NULL)
		ft_error(1);
	e.shot = mlx_xpm_file_to_image(e.mlx, "img/exp.xpm", &e.width, &e.height);
	e.h = -100;
	e.w = -100;
	e.image = fill_weapon(&e);
	e = init_player(e);
	if (e.p.posx == 0 || e.p.posy == 0)
		ft_error(1);
	mlx_hook(e.win, KEYPRESS, KEYPRESSMASK, key_press, &e);
	mlx_hook(e.win, KEYRELEASE, KEYRELEASEMASK, key_release, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop_hook(e.mlx, loop_hook, &e);
	mlx_loop(e.mlx);
}

int					main(void)
{
	ft_init();
	return (0);
}
