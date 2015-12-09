/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 18:04:46 by tauvray           #+#    #+#             */
/*   Updated: 2015/06/10 18:24:39 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			first_x(char **map)
{
	int	x;
	int	y;
	int	res;

	res = 0;
	x = 0;
	y = 0;
	while (map[x])
	{
		while (map[x][y])
		{
			if (map[x][y] == '0')
				res = x;
			y++;
		}
		x++;
		y = 0;
	}
	return (res);
}

t_env		init_player(t_env e)
{
	e.p.posx = first_x(e.map);
	e.p.posy = first_y(e.map);
	e.p.dirx = -1;
	e.qwerty = 1;
	e.p.diry = 0;
	e.sprint = 1;
	e.gun = 1;
	e.p.planex = 0;
	e.p.planey = 0.66;
	e.p.time = 0;
	e.p.oldtime = 0;
	return (e);
}

int			ft_lenmap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (1);
		i++;
	}
	return (0);
}

int			ft_verif_hori(char **map)
{
	int		i;
	int		err;

	i = 0;
	err = 0;
	if (!map[0][0])
		return (1);
	while (map[0][i])
	{
		if (map[0][i] != '1')
			err = 1;
		i++;
	}
	return (err);
}

int			ft_verif_horiend(int cpt, char **map)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	if (!map[cpt - 1][0])
		return (1);
	while (map[cpt - 1][i])
	{
		if (map[cpt - 1][i] != '1')
			err = 1;
		i++;
	}
	return (err);
}
