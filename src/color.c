/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 14:42:20 by gderenzi          #+#    #+#             */
/*   Updated: 2017/04/18 17:28:07 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_min_max(t_map *map)
{
	int		i;
	int		j;
	int		k;
	double	tmin;
	double	tmax;

	i = -1;
	while (++i < map->len)
	{
		j = -1;
		while (++j < map->lines[i]->len - 1)
		{
			k = j;
			while (++k < map->lines[i]->len)
			{
				tmin = ft_min(map->lines[i]->points[j]->z,
						map->lines[i]->points[k]->z);
				tmax = ft_max(map->lines[i]->points[j]->z,
						map->lines[i]->points[k]->z);
				map->min = ft_min(tmin, map->min);
				map->max = ft_max(tmax, map->max);
				map->mid = (map->min + map->max) / 2;
			}
		}
	}
}

int		find_color(t_color *spectrum, int z, double min, double max)
{
	int	t1;
	int	t2;
	int	color;

	if (z <= min)
		return (spectrum->c1);
	if (z >= max)
		return (spectrum->c2);
	t1 = spectrum->c1 / 256 / 256;
	t2 = spectrum->c2 / 256 / 256;
	color = ((((z - fabs(min)) * (t2 - t1)) /
				(max - fabs(min))) + t1) * 256 * 256;
	t1 = spectrum->c1 / 256 % 256;
	t2 = spectrum->c2 / 256 % 256;
	color += ((((z - fabs(min)) * (t2 - t1)) / (max - fabs(min))) + t1) * 256;
	t1 = spectrum->c1 % 256;
	t2 = spectrum->c2 % 256;
	color += ((((z - fabs(min)) * (t2 - t1)) / (max - fabs(min))) + t1);
	return (color);
}

int		get_color(t_win *screen, t_point *p1)
{
	t_color	c;

	if (p1->color < screen->map->min || p1->color > screen->map->max)
		return (0);
	if (p1->color <= screen->map->mid && p1->color >= screen->map->min)
	{
		c.c1 = screen->color[screen->cnum][0];
		c.c2 = screen->color[screen->cnum][1];
		return (find_color(&c, p1->color, screen->map->min, screen->map->mid));
	}
	else if (p1->color <= screen->map->max && p1->color >= screen->map->mid)
	{
		c.c1 = screen->color[screen->cnum][1];
		c.c2 = screen->color[screen->cnum][2];
		return (find_color(&c, p1->color, screen->map->mid, screen->map->max));
	}
	return (0);
}

int		*put_color(int a, int b, int c)
{
	int	*color;

	color = (int *)malloc(sizeof(int) * 3);
	color[0] = a;
	color[1] = b;
	color[2] = c;
	return (color);
}

int		**choose_color(void)
{
	int		**color;

	color = malloc(sizeof(int *) * 2);
	color[0] = put_color(BLACK, GRAY, WHITE);
	color[1] = put_color(RED, ORANGE, YELLOW);
	return (color);
}
