/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 06:04:46 by mchudik           #+#    #+#             */
/*   Updated: 2019/07/19 12:22:55 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	move2(t_w *w)
{
	if (w->up == 1)
	{
		dark(w);
		if (w->map.karta[(int)(w->d.posx + w->d.dirx *
						w->movespeed)][(int)(w->d.posy)] == 0)
			w->d.posx += w->d.dirx * w->movespeed;
		if (w->map.karta[(int)(w->d.posx)][(int)(w->d.posy + w->d.diry *
						w->movespeed)] == 0)
			w->d.posy += w->d.diry * w->movespeed;
	}
	if (w->down == 1)
	{
		dark(w);
		if (w->map.karta[(int)(w->d.posx - w->d.dirx *
						w->movespeed)][(int)(w->d.posy)] == 0)
			w->d.posx -= w->d.dirx * w->movespeed;
		if (w->map.karta[(int)(w->d.posx)][(int)(w->d.posy - w->d.diry *
						w->movespeed)] == 0)
			w->d.posy -= w->d.diry * w->movespeed;
	}
}

void	move3(t_w *w)
{
	double	olddirx;
	double	oldplanex;

	if (w->left == 1)
	{
		dark(w);
		olddirx = w->d.dirx;
		w->d.dirx = w->d.dirx * cos(w->rotspeed) - w->d.diry *
					sin(w->rotspeed);
		w->d.diry = olddirx * sin(w->rotspeed) + w->d.diry *
					cos(w->rotspeed);
		oldplanex = w->d.planex;
		w->d.planex = w->d.planex * cos(w->rotspeed) - w->d.planey *
					sin(w->rotspeed);
		w->d.planey = oldplanex * sin(w->rotspeed) + w->d.planey *
					cos(w->rotspeed);
	}
}

void	move(t_w *w)
{
	double	olddirx;
	double	oldplanex;

	if (w->right == 1)
	{
		dark(w);
		olddirx = w->d.dirx;
		w->d.dirx = w->d.dirx * cos(-w->rotspeed) - w->d.diry *
					sin(-w->rotspeed);
		w->d.diry = olddirx * sin(-w->rotspeed) + w->d.diry *
					cos(-w->rotspeed);
		oldplanex = w->d.planex;
		w->d.planex = w->d.planex * cos(-w->rotspeed) - w->d.planey *
					sin(-w->rotspeed);
		w->d.planey = oldplanex * sin(-w->rotspeed) + w->d.planey *
					cos(-w->rotspeed);
	}
	move3(w);
	move2(w);
}

int		wtrite_key(t_w *w)
{
	move(w);
	if (w->turtle == 1 && w->sonic == 0)
		w->movespeed = 0.025;
	else if (w->turtle == 0 && w->sonic == 0)
		w->movespeed = 0.05;
	if (w->sonic == 1 && w->turtle == 0)
		w->movespeed = 0.1;
	else if (w->sonic == 0 && w->turtle == 0)
		w->movespeed = 0.05;
	threading(w);
	return (0);
}
