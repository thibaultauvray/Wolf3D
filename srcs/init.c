/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 14:28:39 by tauvray           #+#    #+#             */
/*   Updated: 2015/06/06 18:07:04 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			ft_verif_verti(int cpt, char **map)
{
	int	i;
	int	err;

	err = 0;
	i = 0;
	while (i != cpt - 1)
	{
		if (map[i][0] != '1')
			err = 1;
		i++;
	}
	return (err);
}

int			ft_verif_vertiend(int cpt, char **map)
{
	int	i;
	int	len;
	int	err;

	err = 0;
	i = 0;
	len = ft_strlen(map[0]) - 1;
	while (i != cpt - 1)
	{
		if (map[i][len] != '1')
			err = 1;
		i++;
	}
	return (err);
}

int			ft_carre(char **map)
{
	int	i;
	int	j;
	int	err;

	err = 0;
	j = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1')
			{
				if (map[i][j] != '2')
				{
					if (map[i][j] != '0')
						err = 1;
				}
			}
			j++;
		}
		i++;
	}
	return (err);
}

int			verif_map(int cpt, char **map)
{
	int		err;

	if (ft_lenmap(map) == 1)
		return (1);
	err = 0;
	err = ft_verif_hori(map) + err;
	err = ft_verif_horiend(cpt, map) + err;
	err = ft_verif_verti(cpt, map) + err;
	err = ft_verif_vertiend(cpt, map) + err;
	err = ft_carre(map) + err;
	return (err);
}

void		ft_error(int err)
{
	if (err != 0)
		ft_putendl_fd("What did you do to the map, srsly ?", 2);
	exit (1);
}
