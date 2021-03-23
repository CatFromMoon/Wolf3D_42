/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 06:42:17 by mchudik           #+#    #+#             */
/*   Updated: 2019/07/19 11:01:11 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	w_music_2(t_w *w, int key)
{
	if (key == 21)
	{
		w->m.music == 1 ? system("killall afplay") : key;
		system("afplay ./mp3/highway_to_hell.mp3&");
		w->m.music = 1;
	}
	if (key == 22)
	{
		w->m.music == 1 ? system("killall afplay") : key;
		system("afplay ./mp3/thunderstruck.mp3&");
		w->m.music = 1;
	}
	if (key == 23)
	{
		w->m.music == 1 ? system("killall afplay") : key;
		system("afplay ./mp3/hells_bells.mp3&");
		w->m.music = 1;
	}
}

void	w_music(t_w *w, int key)
{
	if (key == 18)
	{
		w->m.music == 1 ? system("killall afplay") : key;
		system("afplay ./mp3/pinc_panter.mp3&");
		w->m.music = 1;
	}
	if (key == 19)
	{
		w->m.music == 1 ? system("killall afplay") : key;
		system("afplay ./mp3/what_is_love.mp3&");
		w->m.music = 1;
	}
	if (key == 20)
	{
		w->m.music == 1 ? system("killall afplay") : key;
		system("afplay ./mp3/run_away.mp3&");
		w->m.music = 1;
	}
	w_music_2(w, key);
}
