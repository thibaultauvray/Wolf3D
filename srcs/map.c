/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 13:32:31 by tauvray           #+#    #+#             */
/*   Updated: 2015/06/10 18:29:03 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int					ft_len(void)
{
	int		fd;
	char	*line;
	int		cpt;

	cpt = 0;
	fd = open("map", O_RDONLY);
	if (fd < 0)
		ft_error(1);
	while (get_next_line(fd, &line) == 1)
	{
		cpt++;
		free(line);
	}
	if (line)
		free(line);
	close (fd);
	return (cpt);
}

int					first_y(char **map)
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
				res = y;
			y++;
		}
		x++;
		y = 0;
	}
	return (res);
}

char				**strsplit_map(void)
{
	int		fd2;
	char	**map;
	char	*line2;
	int		cpt;
	int		i;

	i = 0;
	cpt = ft_len();
	if (!(map = (char **)malloc(sizeof(char *) * cpt + 1)) || cpt < 3)
		return (NULL);
	fd2 = open("map", O_RDONLY);
	while (get_next_line(fd2, &line2) == 1)
	{
		map[i] = ft_strdup(line2);
		ft_putendl(line2);
		free(line2);
		i++;
	}
	close (fd2);
	if (line2)
		free(line2);
	map[i] = NULL;
	if (verif_map(cpt, map) == 1)
		return (NULL);
	return (map);
}
