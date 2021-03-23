/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:03:16 by mchudik           #+#    #+#             */
/*   Updated: 2019/07/19 12:22:35 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	start2(t_w *w)
{
	w->d.camerax = 2 * w->x / (double)W - 1;
	w->d.raydirx = w->d.dirx + w->d.planex * w->d.camerax;
	w->d.raydiry = w->d.diry + w->d.planey * w->d.camerax;
	w->d.mapx = (int)w->d.posx;
	w->d.mapy = (int)w->d.posy;
	w->d.sidedistx = 0;
	w->d.sidedisty = 0;
	w->d.deltadistx = fabs(1 / w->d.raydirx);
	w->d.deltadisty = fabs(1 / w->d.raydiry);
	w->d.perpwalldist = 0;
	w->d.stepx = 0;
	w->d.stepy = 0;
	w->d.hit = 0;
	w->d.side = 0;
}

void	check_w(t_w *w)
{
	if (w->d.raydirx < 0)
	{
		w->d.stepx = -1;
		w->d.sidedistx = (w->d.posx - w->d.mapx) * w->d.deltadistx;
	}
	else
	{
		w->d.stepx = 1;
		w->d.sidedistx = (w->d.mapx + 1.0 - w->d.posx) * w->d.deltadistx;
	}
	if (w->d.raydiry < 0)
	{
		w->d.stepy = -1;
		w->d.sidedisty = (w->d.posy - w->d.mapy) * w->d.deltadisty;
	}
	else
	{
		w->d.stepy = 1;
		w->d.sidedisty = (w->d.mapy + 1.0 - w->d.posy) * w->d.deltadisty;
	}
}

void	jump_wall(t_w *w)
{
	while (w->d.hit == 0)
	{
		if (w->d.sidedistx < w->d.sidedisty)
		{
			w->d.sidedistx += w->d.deltadistx;
			w->d.mapx += w->d.stepx;
			w->d.side = 0;
		}
		else
		{
			w->d.sidedisty += w->d.deltadisty;
			w->d.mapy += w->d.stepy;
			w->d.side = 1;
		}
		if (w->map.karta[w->d.mapx][w->d.mapy] > 0)
			w->d.hit = 1;
	}
	if (w->d.side == 0)
		w->d.perpwalldist = (w->d.mapx - w->d.posx +
				(1 - w->d.stepx) / 2) / w->d.raydirx;
	else
		w->d.perpwalldist = (w->d.mapy - w->d.posy +
				(1 - w->d.stepy) / 2) / w->d.raydiry;
}

void	draw_w(t_w *w)
{
	start2(w);
	check_w(w);
	jump_wall(w);
	drw_st_end(w);
	draw_textures(w);
}

void	*draw_wolf(void *data)
{
	t_w	*w;

	w = (t_w*)data;
	w->x = (double)W / 8 * w->thread_id;
	while (w->x < W)
	{
		draw_w(w);
		w->x++;
	}
	mini_map(w);
	return (data);
}
