/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brez_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 23:48:55 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/18 23:48:57 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				myabs(int a)
{
	return (a >= 0 ? a : -a);
}

static void		add_first(t_line e, t_inf *inf, t_dot *map, int i)
{
	e.d = -e.xlen;
	e.len++;
	while (e.len--)
	{
		mlx_pixel_put(inf->mlx, inf->win, e.x + inf->st_x,\
						e.y + inf->st_y, map[i].color);
		if ((map[i + 1].x - map[i].x) >= 0)
			e.x += 1;
		else
			e.x -= 1;
		e.d += 2 * e.ylen;
		if (e.d > 0)
		{
			e.d -= 2 * e.xlen;
			if ((map[i + 1].y - map[i].y) >= 0)
				e.y += 1;
			else
				e.y -= 1;
		}
	}
	mlx_pixel_put(inf->mlx, inf->win, e.x + inf->st_x,\
					e.y + inf->st_y, map[i].color);
}

static void		add_second(t_line e, t_inf *inf, t_dot *map, int i)
{
	e.d = -e.ylen;
	e.len++;
	while (e.len--)
	{
		mlx_pixel_put(inf->mlx, inf->win, e.x + inf->st_x,\
						e.y + inf->st_y, map[i].color);
		if ((map[i + 1].y - map[i].y) >= 0)
			e.y += 1;
		else
			e.y -= 1;
		e.d += 2 * e.xlen;
		if (e.d > 0)
		{
			e.d -= 2 * e.ylen;
			if ((map[i + 1].x - map[i].x) >= 0)
				e.x += 1;
			else
				e.x -= 1;
		}
	}
}

static void		add_firstver(t_line e, t_inf *inf, t_dot *map, int i)
{
	e.d = -e.xlen;
	e.len++;
	while (e.len--)
	{
		mlx_pixel_put(inf->mlx, inf->win, e.x + inf->st_x,\
						e.y + inf->st_y, map[i].color);
		if ((map[i + inf->max_x].x - map[i].x) >= 0)
			e.x += 1;
		else
			e.x -= 1;
		e.d += 2 * e.ylen;
		if (e.d > 0)
		{
			e.d -= 2 * e.xlen;
			if ((map[i + inf->max_x].y - map[i].y) >= 0)
				e.y += 1;
			else
				e.y -= 1;
		}
	}
	mlx_pixel_put(inf->mlx, inf->win, e.x + inf->st_x,
					e.y + inf->st_y, map[i].color);
}

static void		add_secondver(t_line e, t_inf *inf, t_dot *map, int i)
{
	e.d = -e.ylen;
	e.len++;
	while (e.len--)
	{
		mlx_pixel_put(inf->mlx, inf->win, e.x + inf->st_x,\
						e.y + inf->st_y, map[i].color);
		if ((map[i + inf->max_x].y - map[i].y) >= 0)
			e.y += 1;
		else
			e.y -= 1;
		e.d += 2 * e.xlen;
		if (e.d > 0)
		{
			e.d -= 2 * e.ylen;
			if ((map[i + inf->max_x].x - map[i].x) >= 0)
				e.x += 1;
			else
				e.x -= 1;
		}
	}
}

void			line_gor(t_inf *inf, t_dot *map, int i)
{
	t_line e;

	e.xlen = myabs(map[i + 1].x - map[i].x);
	e.ylen = myabs(map[i + 1].y - map[i].y);
	e.len = max(e.xlen, e.ylen);
	e.x = map[i].x;
	e.y = map[i].y;
	if (e.ylen <= e.xlen)
		add_first(e, inf, map, i);
	else
		add_second(e, inf, map, i);
}

void			line_ver(t_inf *inf, t_dot *map, int i)
{
	t_line e;

	e.xlen = myabs(map[i + inf->max_x].x - map[i].x);
	e.ylen = myabs(map[i + inf->max_x].y - map[i].y);
	e.len = max(e.xlen, e.ylen);
	e.x = map[i].x;
	e.y = map[i].y;
	if (e.ylen <= e.xlen)
		add_firstver(e, inf, map, i);
	else
		add_secondver(e, inf, map, i);
}
