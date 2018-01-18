/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <omakovsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:47:00 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/09 15:47:00 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		transform(char c)
{
	if (c >= 'a' && c <= 'f')
		return (10 + (c - 'a'));
	if (c >= 'A' && c <= 'F')
		return (10 + (c - 'A'));
	if (c >= '0' && c <= '9')
		return (c - 48);
	return (0);
}

static int		ft_atoi_hex(char *str)
{
	int i;
	int hex;
	int rez;

	i = 0;
	hex = 1;
	rez = 0;
	while (str[i] != '\0')
		i++;
	i--;
	while (str[i] != 'x')
	{
		rez = rez + (hex * transform(str[i]));
		hex = hex * 16;
		i--;
	}
	return (rez);
}

static void		write_coord(t_dot **head, char *str, int x, int i)
{
	int j;

	j = 0;
	(*head)[i].z = ft_atoi(str);
	(*head)[i].x = x;
	while (str[j] != '\0')
	{
		if (str[j++] == ',')
			(*head)[i].color = ft_atoi_hex(&str[j]);
	}
}

static int		count_dot(int fd, t_inf *inf)
{
	int		i;
	int		len;
	char	**split;
	char	**tmp;
	char	*line;

	len = 0;
	while (ft_get_next_line(fd, &line) > 0)
	{
		i = 0;
		split = ft_strsplit(line, ' ');
		tmp = split;
		while (split[i])
			free(split[i++]);
		free(tmp);
		if (len == 0)
			inf->max_x = i;
		if (i != inf->max_x)
			return (0);
		len = len + i;
		free(line);
	}
	return (len);
}

static t_dot	*init_map(t_inf *inf, char *str)
{
	t_dot	*map_dots;
	int		len;
	int		fd;

	fd = open(str, O_RDONLY);
	inf->max_x = 0;
	inf->line = 0;
	len = count_dot(fd, inf) - 1;
	if (len == -1)
		return (NULL);
	inf->len = len + 1;
	map_dots = (t_dot*)malloc(sizeof(t_dot) * len);
	if (map_dots == NULL)
		return (NULL);
	while (len >= 0)
	{
		map_dots[len].x = 0;
		map_dots[len].y = 0;
		map_dots[len].z = 0;
		map_dots[len].color = 0xFFFFFF;
		len--;
	}
	close(fd);
	return (map_dots);
}

void			add_read(int *len, int i, char **tmp, char *line)
{
	*len = *len + i;
	free(tmp);
	free(line);
}

t_dot			*read_file(int fd, char *str, t_inf *inf, char *line)
{
	int		i;
	int		len;
	char	**split;
	char	**tmp;
	t_dot	*map_dots;

	len = 0;
	map_dots = init_map(inf, str);
	if (map_dots == NULL)
		return (NULL);
	while (ft_get_next_line(fd, &line) > 0)
	{
		i = 0;
		split = ft_strsplit(line, ' ');
		tmp = split;
		while (split[i])
		{
			write_coord(&map_dots, split[i], i, len + i);
			map_dots[len + i].y = inf->line;
			free(split[i++]);
		}
		add_read(&len, i, tmp, line);
		inf->line++;
	}
	return (map_dots);
}
