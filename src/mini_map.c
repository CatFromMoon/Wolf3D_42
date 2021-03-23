/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 04:04:52 by mchudik           #+#    #+#             */
/*   Updated: 2019/07/19 10:50:31 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	d_sqr(t_w *w, int i, int j, int color)
{
	int	ii;
	int	jj;

	ii = i;
	while (ii < i + w->m.s_x)
	{
		jj = j;
		while (jj < j + w->m.s_y)
		{
			put_pixel_in_img(w, ii, jj, color);
			jj++;
		}
		ii++;
	}
}

void	d_player(t_w *w)
{
	int	ii;
	int	jj;

	ii = w->m.s_x * (int)w->d.posy;
	while (ii < w->m.s_x * (int)w->d.posy + w->m.s_x)
	{
		jj = w->m.s_y * (int)w->d.posx;
		while (jj < w->m.s_y * (int)w->d.posx + w->m.s_y)
		{
			put_pixel_in_img(w, ii, jj, 0xFF0000);
			jj++;
		}
		ii++;
	}
}

void	mini_map(t_w *w)
{
	int	i;
	int	j;
	int	color;

	i = -1;
	color = 0x000000;
	w->m.s_x = MAPW / w->map.h;
	w->m.s_y = MAPH / w->map.w;
	while (++i < w->map.h)
	{
		j = -1;
		while (++j < w->map.w)
		{
			if (w->map.karta[i][j] == 0)
				color = 0xFFFFFF;
			else
				color = 0x000000;
			d_sqr(w, j * w->m.s_x, i * w->m.s_y, color);
		}
	}
	d_player(w);
}
