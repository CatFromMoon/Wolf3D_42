/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 20:30:38 by mchudik           #+#    #+#             */
/*   Updated: 2019/07/19 10:25:30 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		start_pl(t_w *w)
{
	int i;
	int j;

	i = w->map.h - 1;
	while (--i > 0)
	{
		j = w->map.w - 1;
		while (--j > 0)
			if (w->map.karta[i][j] == 0)
			{
				w->d.posx = i + 0.5;
				w->d.posy = j + 0.5;
				return (0);
			}
	}
	return (0);
}

int		valid2(t_w *w)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	while (++i < w->map.h - 1)
	{
		j = 0;
		while (++j < w->map.w - 1)
			w->map.karta[i][j] == 0 ? k++ : k;
	}
	w->m.null_k = k;
	if (k == 0)
		return (-1);
	return (0);
}

int		valid(t_w *w)
{
	int i;

	if (w->map.h < 3 || w->map.w < 3)
		return (-1);
	i = -1;
	while (++i < w->map.w)
		if (w->map.karta[0][i] == 0 || w->map.karta[w->map.h - 1][i] == 0)
			return (-1);
	i = -1;
	while (++i < w->map.h)
		if (w->map.karta[i][0] == 0 || w->map.karta[i][w->map.w - 1] == 0)
			return (-1);
	if (valid2(w) == -1)
		return (-1);
	else
		start_pl(w);
	return (0);
}
