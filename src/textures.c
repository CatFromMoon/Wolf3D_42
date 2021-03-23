/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 22:46:05 by mchudik           #+#    #+#             */
/*   Updated: 2019/07/19 11:09:24 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	draw_textures(t_w *w)
{
	int	y;

	if (w->d.side == 0)
		w->d.wallx = w->d.posy + w->d.perpwalldist * w->d.raydiry;
	else
		w->d.wallx = w->d.posx + w->d.perpwalldist * w->d.raydirx;
	w->d.wallx -= floor(w->d.wallx);
	w->d.tex_x = (int)(w->d.wallx * (double)(w->d.textw));
	if (w->d.side == 0 && w->d.raydirx > 0)
		w->d.tex_x = w->d.textw - w->d.tex_x - 1;
	if (w->d.side == 1 && w->d.raydiry < 0)
		w->d.tex_x = w->d.textw - w->d.tex_x - 1;
	y = w->d.drawstart;
	while (y < w->d.drawend)
	{
		w->d.d = y * 256 - H * 128 + w->d.lineheight * 128;
		w->d.tex_y = ((w->d.d * w->d.texth) / w->d.lineheight) / 256;
		normw(w);
		put_pixel_in_img(w, w->x, y, w->d.color);
		y++;
	}
}

void	load_textures_3(t_w *w, int x, int y)
{
	if (!(w->iron = mlx_xpm_file_to_image(w->win.mlx_ptr,
			"textures/iron.xpm", &x, &y)))
	{
		ft_putstr("error textures iron.xpm");
		exit(0);
	}
	if (!(w->color = mlx_xpm_file_to_image(w->win.mlx_ptr,
					"textures/colorstone.xpm", &x, &y)))
	{
		ft_putstr("error textures colorstone.xpm");
		exit(0);
	}
	if (!(w->wood = mlx_xpm_file_to_image(w->win.mlx_ptr,
					"textures/wood.xpm", &x, &y)))
	{
		ft_putstr("error textures wood.xpm");
		exit(0);
	}
}

void	load_textures_2(t_w *w, int x, int y)
{
	if (!(w->eagle = mlx_xpm_file_to_image(w->win.mlx_ptr,
					"textures/eagle.xpm", &x, &y)))
	{
		ft_putstr("error textures eagle.xpm");
		exit(0);
	}
	if (!(w->mossy = mlx_xpm_file_to_image(w->win.mlx_ptr,
					"textures/mossy.xpm", &x, &y)))
	{
		ft_putstr("error textures mossy.xpm");
		exit(0);
	}
	if (!(w->purple = mlx_xpm_file_to_image(w->win.mlx_ptr,
					"textures/purplestone.xpm", &x, &y)))
	{
		ft_putstr("error textures purplestone.xpm");
		exit(0);
	}
	load_textures_3(w, x, y);
}

void	load_textures(t_w *w)
{
	int	x;
	int	y;

	if (!(w->blue = mlx_xpm_file_to_image(w->win.mlx_ptr,
					"textures/bluestone.xpm", &x, &y)))
	{
		ft_putstr("error textures bluestone.xpm");
		exit(0);
	}
	if (!(w->red = mlx_xpm_file_to_image(w->win.mlx_ptr,
					"textures/redbrick.xpm", &x, &y)))
	{
		ft_putstr("error textures redbrick.xpm");
		exit(0);
	}
	if (!(w->grey = mlx_xpm_file_to_image(w->win.mlx_ptr,
					"textures/greystone.xpm", &x, &y)))
	{
		ft_putstr("error textures greystone.xpm");
		exit(0);
	}
	load_textures_2(w, x, y);
}
