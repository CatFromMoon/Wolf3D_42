/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:56:40 by mchudik           #+#    #+#             */
/*   Updated: 2019/07/19 10:42:21 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	color_texture_2(t_w *w)
{
	if (w->d.side == 0 && w->d.raydirx > 0)
		w->d.color = ((unsigned int *)(w->red->data))[w->d.texth *
									w->d.tex_y + w->d.tex_x];
	else if (w->d.side == 0 && w->d.raydirx < 0)
		w->d.color = ((unsigned int *)(w->color->data))[w->d.texth *
									w->d.tex_y + w->d.tex_x];
	else if (w->d.side == 1 && w->d.raydiry < 0)
		w->d.color = ((unsigned int *)(w->blue->data))[w->d.texth *
									w->d.tex_y + w->d.tex_x];
	else if (w->d.side == 1 && w->d.raydiry > 0)
		w->d.color = ((unsigned int *)(w->iron->data))[w->d.texth *
									w->d.tex_y + w->d.tex_x];
	else
		w->d.color = 0xffff00;
}

void	color_text(t_w *w)
{
	if (w->d.textnum == 5)
		w->d.color = ((unsigned int *)(w->purple->data))[w->d.texth *
							w->d.tex_y + w->d.tex_x];
	if (w->d.textnum == 6)
		w->d.color = ((unsigned int *)(w->mossy->data))[w->d.texth *
							w->d.tex_y + w->d.tex_x];
	if (w->d.textnum == 7)
		w->d.color = ((unsigned int *)(w->wood->data))[w->d.texth *
							w->d.tex_y + w->d.tex_x];
	if (w->d.textnum == 8)
		w->d.color = ((unsigned int *)(w->eagle->data))[w->d.texth *
							w->d.tex_y + w->d.tex_x];
	if (w->d.textnum == 9)
		w->d.color = ((unsigned int *)(w->iron->data))[w->d.texth *
							w->d.tex_y + w->d.tex_x];
}

void	color_texture(t_w *w)
{
	w->d.textnum = w->map.karta[w->d.mapx][w->d.mapy];
	if (w->d.textnum == 1)
		w->d.color = ((unsigned int *)(w->red->data))[w->d.texth *
							w->d.tex_y + w->d.tex_x];
	if (w->d.textnum == 2)
		w->d.color = ((unsigned int *)(w->blue->data))[w->d.texth *
							w->d.tex_y + w->d.tex_x];
	if (w->d.textnum == 3)
		w->d.color = ((unsigned int *)(w->color->data))[w->d.texth *
							w->d.tex_y + w->d.tex_x];
	if (w->d.textnum == 4)
		w->d.color = ((unsigned int *)(w->grey->data))[w->d.texth *
							w->d.tex_y + w->d.tex_x];
	color_text(w);
}

void	normw(t_w *w)
{
	if (w->norw == 1)
	{
		color_texture(w);
		if (w->d.side == 1)
			w->d.color = (w->d.color >> 1) & 8355711;
	}
	else
		color_texture_2(w);
}
