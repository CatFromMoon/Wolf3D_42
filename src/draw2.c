/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:58:34 by mchudik           #+#    #+#             */
/*   Updated: 2019/07/19 12:22:40 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	drw_st_end(t_w *w)
{
	w->d.lineheight = (int)(H / w->d.perpwalldist);
	w->d.drawstart = -w->d.lineheight / 2 + H / 2;
	if (w->d.drawstart < 0)
		w->d.drawstart = 0;
	w->d.drawend = w->d.lineheight / 2 + H / 2;
	if (w->d.drawend >= H)
		w->d.drawend = H - 1;
}

void	color_2(t_w *w)
{
	int	y;

	y = w->d.drawend;
	while (y < H)
	{
		w->d.f_d = ((H / (2.0 * y - H)) / w->d.perpwalldist);
		w->d.f_t_x = (int)((w->d.f_d * w->d.f_d_x +
					(1.0 - w->d.f_d) * w->d.posx) * w->d.texth) % w->d.textw;
		w->d.f_t_y = (int)((w->d.f_d * w->d.f_d_y +
					(1.0 - w->d.f_d) * w->d.posy) * w->d.texth) % w->d.textw;
		put_pixel_in_img(w, w->x, y, ((unsigned int *)(w->sand->data))
				[w->d.textw * w->d.f_t_y + w->d.f_t_x]);
		y++;
	}
}

void	color(t_w *w)
{
	if (w->d.side == 0 && w->d.dirx >= 0)
	{
		w->d.f_d_x = w->d.mapx;
		w->d.f_d_y = w->d.mapy + w->d.wallx;
	}
	else if (w->d.side == 0 && w->d.dirx < 0)
	{
		w->d.f_d_x = w->d.mapx + 1.0;
		w->d.f_d_y = w->d.mapy + w->d.wallx;
	}
	else if (w->d.side == 1 && w->d.diry >= 0)
	{
		w->d.f_d_x = w->d.mapx + w->d.wallx;
		w->d.f_d_y = w->d.mapy;
	}
	else if (w->d.side == 1 && w->d.diry < 0)
	{
		w->d.f_d_x = w->d.mapx + w->d.wallx;
		w->d.f_d_y = w->d.mapy + 1.0;
	}
	color_2(w);
}
