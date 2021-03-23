/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <mchudik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:05:02 by mchudik           #+#    #+#             */
/*   Updated: 2018/11/20 19:05:28 by mchudik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int sq;
	int n;

	sq = 0;
	n = 0;
	while (sq < nb)
	{
		n++;
		sq = n * n;
	}
	if (sq == nb)
		return (n);
	else
		return (0);
}