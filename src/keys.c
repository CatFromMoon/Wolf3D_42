/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:00:02 by mchudik           #+#    #+#             */
/*   Updated: 2019/07/19 10:44:01 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	dark(t_w *w)
{
	int i;
	int j;

	i = -1;
	while (++i < W)
	{
		j = -1;
		while (++j < H / 2)
			put_pixel_in_img(w, i, j, 0x87CEEB);
	}
	i = -1;
	while (++i < W)
	{
		j = H / 2;
		while (++j < H)
			put_pixel_in_img(w, i, j, 0x8B4513);
	}
}

void	menu_k(t_w *w, int key)
{
	if (key == 48 && w->menu.m_menu == 1)
		menu(w, key);
	if (key == 48 && w->menu.m_menu == 2)
		menu_key(key, w);
}

int		press(int key, t_w *w)
{
	w_music(w, key);
	if (key == 123)
		w->left = 1;
	if (key == 124)
		w->right = 1;
	if (key == 126)
		w->up = 1;
	if (key == 125)
		w->down = 1;
	if (key == 49)
		w->turtle = 1;
	if (key == 1)
		w->sonic = 1;
	if (key == 45 && w->norw == 0)
		w->norw = 1;
	else if (key == 45 && w->norw == 1)
		w->norw = 0;
	menu_k(w, key);
	if (key == 53)
	{
		w->m.music == 0 ? key : system("killall afplay");
		exit(1);
	}
	return (0);
}

int		un_press(int key, t_w *w)
{
	if (key == 123)
		w->left = 0;
	if (key == 124)
		w->right = 0;
	if (key == 126)
		w->up = 0;
	if (key == 125)
		w->down = 0;
	if (key == 49)
		w->turtle = 0;
	if (key == 1)
		w->sonic = 0;
	return (0);
}
