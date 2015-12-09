/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 15:28:06 by tauvray           #+#    #+#             */
/*   Updated: 2015/06/10 18:24:29 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include <math.h>

# define WIDTH 800
# define MLX_BIG_ENDIAN 1
# define HEIGHT 600
# define KEYPRESS		(2)
# define KEYRELEASE		(3)
# define KEYPRESSMASK	(1L<<0)
# define KEYRELEASEMASK	(1L<<1)

typedef unsigned int	t_uint32;

typedef struct		s_per
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			time;
	double			oldtime;
	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	int				mapy;
	int				mapx;
	double			sidedisty;
	double			sidedistx;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			olddirx;
	double			olddiry;
	double			oldplanex;
	double			oldplaney;
	double			movespeed;
	double			rotspeed;
}					t_per;

typedef struct		s_env
{
	void			*win;
	void			*mlx;
	void			*img;
	char			**map;
	void			**image;
	int				height;
	int				width;
	int				gun;
	char			*gunname;
	int				qwerty;
	int				bpx;
	int				szl;
	int				endiant;
	char			*edit;
	int				up;
	int				down;
	int				left;
	int				w;
	int				h;
	void			*shot;
	int				right;
	int				sprint;
	t_per			p;
}					t_env;

typedef struct		s_rgb
{
	int				r;
	int				b;
	int				g;
	int				c;
}					t_rgb;

int					key_hook(int keyconde, t_env *e);
t_env				init_player(t_env e);
void				draw_wolf(t_env *e);
void				pxl_to_img(t_env *e, int x, int y, int color);
int					key_release(int keycode, t_env *e);
int					key_press(int keycode, t_env *e);
void				ft_error(int err);
int					verif_map(int cpt, char **map);
char				**strsplit_map(void);
int					ft_len(void);
int					first_y(char **map);
void				distance_wall(t_env *e);
void				weapon(t_env *e);
void				detect_wall(t_env *e);
void				ray_step(t_env *e);
void				init_loop(int x, t_env *e);
void				ray_move(t_env *e);
void				ray_move2(t_env *e);
void				draw_wolf(t_env *e);
void				draw_yi(int x, t_env *e);
char				**strsplit_map(void);
void				destroy_img(t_env *e);
int					ft_lenmap(char **map);
int					ft_verif_hori(char **map);
int					ft_verif_horiend(int cpt, char **map);
int					expose_hook(t_env *e);
int					loop_hook(t_env *e);

#endif
