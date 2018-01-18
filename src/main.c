/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 20:58:34 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/18 20:58:39 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_dot	*map;
	t_inf	inf;
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	map = NULL;
	line = NULL;
	inf.line = 0;
	if (argc == 2)
	{
		if (!(map = read_file(fd, argv[1], &inf, line)))
		{
			ft_putstr("It is wrong map. Check your file!\n");
			return (0);
		}
		draw_map(&map, &inf);
	}
	else
		ft_putstr("Usage : ./fdf <filename>");
	free(map);
	close(fd);
	return (0);
}
