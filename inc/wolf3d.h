/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 17:25:48 by mchudik           #+#    #+#             */
/*   Updated: 2019/07/19 12:35:38 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define W 1440
# define H 720
# define MAPH 150
# define MAPW 200

# include "../libft/libft.h"
# include "mlx.h"
# include "stdlib.h"
# include "pthread.h"
# include "math.h"

typedef	struct	s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_window;

typedef struct	s_map
{
	int			**karta;
	int			h;
	int			w;
	int			fd;
	int			fd_error;
	int			error;
}				t_map;

typedef struct	s_draw
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		time;
	double		oldtime;
	double		camerax;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			color;
	int			textw;
	int			texth;
	int			textnum;
	int			tex_x;
	double		wallx;
	int			d;
	int			tex_y;
	double		f_d_x;
	double		f_d_y;
	double		f_d;
	int			f_t_x;
	int			f_t_y;
}				t_draw;

typedef	struct	s_menu
{
	int			m_menu;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_menu;

typedef struct	s_image
{
	int			*image;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}				t_image;

typedef struct	s_textures
{
	int			w;
	int			h;
	char		*data;
}				t_textures;

typedef struct	s_mini_map
{
	int			null_k;
	int			s_x;
	int			s_y;
	int			music;
}				t_mini_map;

typedef struct	s_f
{
	double		x;
	t_map		map;
	t_window	win;
	t_draw		d;
	t_image		img;
	t_textures	*blue;
	t_textures	*red;
	t_textures	*color;
	t_textures	*grey;
	t_textures	*purple;
	t_textures	*mossy;
	t_textures	*wood;
	t_textures	*eagle;
	t_textures	*iron;
	t_textures	*sand;
	t_mini_map	m;
	t_menu		menu;
	int			thread_id;
	double		rotspeed;
	double		movespeed;
	int			up;
	int			down;
	int			left;
	int			right;
	int			norw;
	int			sonic;
	int			turtle;
}				t_w;

void			draw(t_w *w);
void			draw_w(t_w *w);
void			draw_line(t_w *w);
void			color(t_w *w);
void			threading(t_w *w);
void			dark(t_w *w);
void			put_pixel_in_img(t_w *w, int x, int y, int color);
void			*draw_wolf(void *data);
int				wtrite_key(t_w *w);
int				mouse_close(int key, t_w *w);
int				ft_read_2(char *argv, t_w *w);
int				number_spases(char *line);
int				read_file(char *argv, t_w *w);
int				valid(t_w *w);
void			start(t_w *w);
void			load_textures(t_w *w);
void			drw_st_end(t_w *w);
void			draw_textures(t_w *w);
void			mini_map(t_w *w);
int				un_press(int key, t_w *w);
int				press(int key, t_w *w);
void			w_music(t_w *w, int key);
void			for_mini_map(t_w *w);
void			normw(t_w *w);
int				menu_key(int key, t_w *w);
void			menu_k(t_w *w, int key);
void			menu(t_w *w, int key);
#endif
