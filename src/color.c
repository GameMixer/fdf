/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 14:42:20 by gderenzi          #+#    #+#             */
/*   Updated: 2017/04/20 14:21:10 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

//int		get_color(t_win *screen, int color, t_point *p1)
int		get_color(t_win *screen, t_point *p1, t_point *p2)
{
	t_color	c;
	int		color;

	if (out_window(p1) == 1)
	{
		if (p2->color > p1->color)
			color = p2->color;
		else
			color = p1->color;
		if (color < screen->map->min || color > screen->map->max)
			return (0);
		if (color <= screen->map->mid && color >= screen->map->min)
		{
			c.c1 = screen->color[screen->cnum][0];
			c.c2 = screen->color[screen->cnum][1];
			return (find_color(&c, color, screen->map->min, screen->map->mid));
		}
		else if (color <= screen->map->max && color >= screen->map->mid)
		{
			c.c1 = screen->color[screen->cnum][1];
			c.c2 = screen->color[screen->cnum][2];
			return (find_color(&c, color, screen->map->mid, screen->map->max));
		}
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

	color = malloc(sizeof(int *) * THEMES);
	color[0] = put_color(BLACK, GRAY, WHITE);
	color[1] = put_color(BLUE, LIME, RED);
	color[2] = put_color(RED, ORANGE, YELLOW);
	color[3] = put_color(RED, PINK, WHITE);
	color[4] = put_color(SCIBLUE, DEEPSKYBLUE, CREAMCAN);
	return (color);
}
