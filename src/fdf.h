/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <omakovsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:51:00 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/09 16:27:37 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct		s_line
{
	int				x;
	int				y;
	int				d;
	int				len;
	int				xlen;
	int				ylen;
}					t_line;

typedef struct		s_dot
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_dot;

typedef struct		s_inf
{
	void			*mlx;
	void			*win;
	int				max_x;
	int				line;
	int				len;
	int				st_x;
	int				st_y;
}					t_inf;

t_dot				*read_file(int fd, char *str, t_inf *inf, char *line);
void				draw_map(t_dot **map, t_inf *inf);
int					max(int a, int b);
void				size_step(t_dot **map, t_inf *inf);
void				change_coord(int n, t_dot **map, t_inf *inf);
void				line_gor(t_inf *inf, t_dot *map, int i);
void				line_ver(t_inf *inf, t_dot *map, int i);
void				rotate_matrix(t_dot **map, t_inf *inf);

#endif
