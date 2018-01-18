/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 23:41:16 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/18 23:41:17 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_matrix(t_dot **map, t_inf *inf)
{
	int i;
	int tmpy;
	int tmpz;
	int tmpx;

	i = 0;
	while (i < inf->len)
	{
		tmpy = (*map)[i].y;
		(*map)[i].y = (int)(tmpy * cos(0.9) - (*map)[i].z * sin(0.9));
		(*map)[i].z = (int)(tmpy * sin(0.9) + (*map)[i].z * cos(0.9));
		tmpz = (*map)[i].z;
		(*map)[i].z = (int)(tmpz * cos(0) - (*map)[i].x * sin(0));
		(*map)[i].x = (int)(tmpz * sin(0) + (*map)[i].x * cos(0));
		tmpx = (*map)[i].x;
		(*map)[i].x = (int)(tmpx * cos(0) - (*map)[i].y * sin(0));
		(*map)[i].y = (int)(tmpx * sin(0) + (*map)[i].y * cos(0));
		i++;
	}
}
