/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:57:37 by mchudik           #+#    #+#             */
/*   Updated: 2019/07/19 09:40:28 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	init_img(t_w *w)
{
	int	bpp;
	int	sizeline;
	int	endian;

	w->img.image = mlx_new_image(w->win.mlx_ptr, W, H);
	w->img.data = mlx_get_data_addr(w->img.image, &bpp, &sizeline, &endian);
	w->img.bpp = bpp;
	w->img.sizeline = sizeline;
	w->img.endian = endian;
}

void	start(t_w *w)
{
	w->menu.m_menu = 1;
	w->turtle = 0;
	w->sonic = 0;
	w->norw = 0;
	w->m.music = 0;
	w->d.textw = 64;
	w->d.texth = 64;
	w->up = 0;
	w->down = 0;
	w->right = 0;
	w->left = 0;
	w->d.dirx = -1;
	w->d.diry = 0;
	w->d.planex = 0;
	w->d.planey = 0.66;
	w->d.time = 0;
	w->d.oldtime = 0;
	w->rotspeed = 0.04;
	w->movespeed = 0.05;
}

void	put_pixel_in_img(t_w *w, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && x < W && y < H)
		*(int *)&w->img.data[(x * w->img.bpp >> 3) +
							(y * w->img.sizeline)] = color;
}

void	draw(t_w *w)
{
	w->win.mlx_ptr = mlx_init();
	w->win.win_ptr = mlx_new_window(w->win.mlx_ptr, W, H, "Wolf 3d");
	init_img(w);
	load_textures(w);
	dark(w);
	start(w);
	threading(w);
	mlx_hook(w->win.win_ptr, 2, 0, press, w);
	mlx_hook(w->win.win_ptr, 3, 0, un_press, w);
	mlx_loop_hook(w->win.mlx_ptr, wtrite_key, w);
	mlx_hook(w->win.win_ptr, 17, 0, mouse_close, w);
	mlx_loop(w->win.mlx_ptr);
}
