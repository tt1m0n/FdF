/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <omakovsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 10:21:00 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/10 10:21:00 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int		my_key_hook(int keycode, void *param)
{
	if (keycode == 53)
	{
		param = NULL;
		exit(1);
	}
	return (0);
}

int		exit_x(void *param)
{
	param = NULL;
	exit(1);
	return (0);
}

void	change_coord(int n, t_dot **map, t_inf *inf)
{
	int i;

	i = 0;
	while (i < inf->len)
	{
		(*map)[i].x = (*map)[i].x * n;
		(*map)[i].y = (*map)[i].y * n;
		i++;
	}
	inf->st_x = 500 - (inf->max_x * (*map)[1].x / 2);
	inf->st_y = 400 - (inf->line * (*map)[1].x / 2);
}

void	resize(t_dot **map, t_inf *inf)
{
	int n;
	int pix;

	pix = 0;
	n = max(inf->max_x, inf->line);
	if (n >= 0 && n <= 30)
		pix = 20;
	if (n > 30 && n <= 60)
		pix = 10;
	if (n > 60 && n <= 120)
		pix = 5;
	if (n > 120 && n <= 300)
		pix = 3;
	if (n > 300)
		pix = 1;
	change_coord(pix, map, inf);
}

void	draw_map(t_dot **map, t_inf *inf)
{
	int i;

	i = 0;
	resize(map, inf);
	rotate_matrix(map, inf);
	inf->mlx = mlx_init();
	inf->win = mlx_new_window(inf->mlx, 1000, 800, "my FdF");
	while (i < (inf->len - 1))
	{
		if ((i - i / inf->max_x) % (inf->max_x - 1) != 0)
			line_gor(inf, *map, i);
		if ((i % inf->max_x == 0))
			line_gor(inf, *map, i);
		if (i < (inf->len - inf->max_x))
			line_ver(inf, *map, i);
		i++;
	}
	mlx_key_hook(inf->win, my_key_hook, 0);
	mlx_hook(inf->win, 17, 1L << 17, exit_x, 0);
	mlx_loop(inf->mlx);
}
