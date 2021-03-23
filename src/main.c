/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 17:42:28 by mchudik           #+#    #+#             */
/*   Updated: 2019/07/19 10:45:03 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	threading(t_w *w)
{
	pthread_t	thr[8];
	t_w			mass[8];

	w->thread_id = 0;
	while (w->thread_id < 8)
	{
		ft_memcpy((void *)&mass[w->thread_id], (void *)w, sizeof(t_w));
		mass[w->thread_id].x = w->thread_id * 8;
		pthread_create(&thr[w->thread_id], NULL, draw_wolf,
									&mass[w->thread_id]);
		w->thread_id++;
	}
	w->thread_id = 0;
	while (w->thread_id < 8)
	{
		pthread_join(thr[w->thread_id], NULL);
		w->thread_id++;
	}
	mlx_put_image_to_window(w->win.mlx_ptr, w->win.win_ptr,
							w->img.image, 0, 0);
}

int		main(int argc, char *arg[])
{
	t_w *w;

	argc < 2 ? ft_putstr("no file to read\n") : argc;
	argc > 2 ? ft_putstr("too many files\n") : argc;
	if (argc == 2)
	{
		w = (t_w*)malloc(sizeof(t_w));
		if (ft_read_2(arg[1], w) == -1)
		{
			ft_putstr("error file");
			exit(1);
		}
		read_file(arg[1], w);
		if (valid(w) == -1)
		{
			ft_putstr("give me valid file");
			exit(1);
		}
		draw(w);
	}
	return (0);
}
