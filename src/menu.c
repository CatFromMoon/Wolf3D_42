/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:39:38 by mchudik           #+#    #+#             */
/*   Updated: 2019/07/19 10:46:39 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		menu_key(int key, t_w *w)
{
	if (key == 48)
	{
		w->menu.m_menu = 1;
		mlx_destroy_window(w->menu.mlx_ptr, w->menu.win_ptr);
	}
	return (0);
}

void	lib_music(t_w *w)
{
	mlx_string_put(w->menu.mlx_ptr, w->menu.win_ptr, 70,
			100, 0xFF4500, "'1' pinc_panter");
	mlx_string_put(w->menu.mlx_ptr, w->menu.win_ptr, 70,
			120, 0xFF4500, "'2' what_is_love");
	mlx_string_put(w->menu.mlx_ptr, w->menu.win_ptr, 70,
			140, 0xFF4500, "'3' run_away");
	mlx_string_put(w->menu.mlx_ptr, w->menu.win_ptr, 70,
			160, 0xFF4500, "'4' highway_to_hell");
	mlx_string_put(w->menu.mlx_ptr, w->menu.win_ptr, 70,
			180, 0xFF4500, "'5' thunderstruck");
	mlx_string_put(w->menu.mlx_ptr, w->menu.win_ptr, 70,
			200, 0xFF4500, "'6' hells_bells");
}

void	menu(t_w *w, int key)
{
	threading(w);
	if (w->menu.m_menu == 1)
	{
		key = 1;
		w->menu.m_menu = 2;
		w->menu.mlx_ptr = mlx_init();
		w->menu.win_ptr = mlx_new_window(w->menu.mlx_ptr, 800, 800, "MENU");
		mlx_hook(w->menu.win_ptr, 2, 0, menu_key, w);
		mlx_string_put(w->menu.mlx_ptr, w->menu.win_ptr, 0,
			0, 0xFF4500, "Use:");
		mlx_string_put(w->menu.mlx_ptr, w->menu.win_ptr, 50,
			0, 0xFF4500, "'n' for change wall textures");
		mlx_string_put(w->menu.mlx_ptr, w->menu.win_ptr, 50,
			20, 0xFF4500, "'s' for move like a sonic");
		mlx_string_put(w->menu.mlx_ptr, w->menu.win_ptr, 50,
			40, 0xFF4500, "'spase' for move like a turtle");
		mlx_string_put(w->menu.mlx_ptr, w->menu.win_ptr, 0,
			80, 0xFF4500, "Music:");
		lib_music(w);
		mlx_loop(w->menu.mlx_ptr);
	}
}
