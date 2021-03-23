/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 18:01:21 by mchudik           #+#    #+#             */
/*   Updated: 2019/07/08 21:59:01 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	str_to_mass_num(char **map, t_w *w)
{
	char	**tmp;
	int		x;
	int		y;

	y = 0;
	w->map.karta = (int**)malloc(sizeof(int*) * w->map.h);
	while (y < w->map.h)
	{
		w->map.karta[y] = (int*)malloc(sizeof(int) * w->map.w);
		tmp = ft_strsplit(map[y], ' ');
		free(map[y]);
		x = 0;
		while (x < w->map.w)
		{
			w->map.karta[y][x] = atoi(tmp[x]);
			free(tmp[x]);
			x++;
		}
		free(tmp);
		y++;
	}
	free(map);
}

int		ft_count_words(char const *s, char c)
{
	int		word;
	int		i;

	word = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			while (s[i] && s[i] != c)
				i++;
			word++;
		}
	}
	return (word);
}

char	*next_step(t_w *w, char *buf, char *tmp, char *line)
{
	if (!(ft_isdigit(*line) || *line == ' ' || *line == '\n'))
	{
		line++;
		return (0);
	}
	if (w->map.w == ft_count_words(line, ' ') || w->map.h == 1)
		w->map.w = ft_count_words(line, ' ');
	else
	{
		ft_putstr("give me valid file");
		exit(0);
	}
	tmp = ft_strjoin(buf, line);
	free(buf);
	free(line);
	buf = ft_strjoin(tmp, "\n");
	free(tmp);
	return (buf);
}

void	check(t_w *w)
{
	if (!w->map.w || w->map.error == -1)
	{
		ft_putstr("error file");
		exit(0);
	}
}

int		read_file(char *argv, t_w *w)
{
	char	*line;
	char	*buf;
	char	**map;
	char	*tmp;

	tmp = NULL;
	w->map.h = 0;
	if ((w->map.fd = open(argv, O_RDONLY)) < 0)
		w->map.error = -1;
	buf = ft_strdup("\0");
	while (((get_next_line(w->map.fd, &line)) > 0) && ++w->map.h)
	{
		(w->map.w != number_spases(line) ?
			w->map.error = -1 : w->map.w);
		buf = next_step(w, buf, tmp, line);
	}
	free(line);
	check(w);
	close(w->map.fd);
	map = ft_strsplit(buf, '\n');
	free(buf);
	str_to_mass_num(map, w);
	close(w->map.fd);
	return (0);
}
