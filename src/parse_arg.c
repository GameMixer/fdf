/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:52:00 by gderenzi          #+#    #+#             */
/*   Updated: 2017/04/13 11:11:12 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_points(char *line, int nb_line, t_point ***array_points)
{
	char	**str_array;
	t_point	*point;
	int		i;

	str_array = ft_strsplit(line, ' ');
	i = 0;
	while (str_array[i] != 0)
		i++;
	if (!((*array_points) = (t_point **)malloc(sizeof(t_point) * i)))
		fdf_malloc_error();
	i = 0;
	while (str_array[i] != 0)
	{
		if (!(point = (t_point *)malloc(sizeof(t_point))))
			fdf_malloc_error();
		point->x = i * SIZE_W;
		point->y = nb_line * SIZE_H;
		point->z = ft_atoi(str_array[i]);
		point->color = point->z;
		(*array_points)[i] = point;
		i++;
	}
	return (i);
}

int		ft_row_num(char *map)
{
	int		fd;
	int		num_lines;
	char	buf;

	fd = 0;
	num_lines = 0;
	if ((fd = open(map, O_RDONLY)) < 0)
		fdf_map_error();
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
			num_lines++;
	}
	close(fd);
	return (num_lines);
}

t_map	*ft_parse_map(char *av, int fd)
{
	char	*line;
	t_map	*map;
	int		count;
	t_line	*row;
	t_point	**array_points;

	count = 0;
	if (!(map = (t_map *)malloc(sizeof(t_map))) ||
			!(map->lines = (t_line **)malloc(sizeof(t_line) * ft_row_num(av))))
		fdf_malloc_error();
	map->len = 0;
	if ((fd = open(av, O_RDONLY)) > 0)
	{
		while ((get_next_line(fd, &line)) > 0)
		{
			if (!(row = (t_line *)malloc(sizeof(t_line))))
				fdf_malloc_error();
			row->len = ft_points(line, count, &array_points);
			row->points = array_points;
			map->lines[count] = row;
			count++;
		}
		map->len = count;
	}
	return (map);
}
