/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 15:16:48 by tauvray           #+#    #+#             */
/*   Updated: 2015/06/10 18:13:58 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		free_tab(t_env **e)
{
	int	i;

	i = 0;
	while ((*e)->map[i])
	{
		free((*e)->map[i]);
		(*e)->map[i] = NULL;
		i++;
	}
	free((*e)->map);
	(*e)->map = NULL;
}

void		destroy_img(t_env *e)
{
	free_tab(&e);
	mlx_destroy_image(e->mlx, e->img);
	mlx_destroy_image(e->mlx, e->image[0]);
	mlx_destroy_image(e->mlx, e->image[1]);
	mlx_destroy_image(e->mlx, e->image[2]);
	mlx_destroy_image(e->mlx, e->shot);
	free(e->image);
	mlx_destroy_window(e->mlx, e->win);
	free(e->mlx);
	exit (1);
}
