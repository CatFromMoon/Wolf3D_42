/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 18:28:12 by mchudik           #+#    #+#             */
/*   Updated: 2019/07/19 10:20:39 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		check_line(char *line, t_w *w)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (line[i] != '\0')
	{
		if (line[i] >= 48 && line[i] <= 57)
		{
			k++;
			k > 1 ? w->map.error = -1 : k;
			i++;
		}
		else if (line[i] == 32)
		{
			i++;
			k = 0;
		}
		else
		{
			w->map.error = -1;
			break ;
		}
	}
	return (i);
}

int		number_spases(char *line)
{
	int		i;
	int		k;

	k = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
		{
			k++;
			while (line[i] == ' ')
				i++;
		}
		else
			i++;
	}
	if (line[i - 1] == ' ' || line[0] == ' ')
		k--;
	return (k + 1);
}

int		ft_read_2(char *argv, t_w *w)
{
	char	*line;
	int		k;

	k = 0;
	w->map.w = 0;
	w->map.error = 0;
	if ((w->map.fd_error = open(argv, O_RDONLY)) < 0)
		return (-1);
	while ((k = get_next_line(w->map.fd_error, &line)) > 0)
	{
		if (check_line(line, w) != 0)
			w->map.w = number_spases(line);
		else
			w->map.error = -1;
		free(line);
	}
	if (k != -1)
		free(line);
	return (w->map.error);
}
