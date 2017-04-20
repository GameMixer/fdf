/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 14:06:14 by gderenzi          #+#    #+#             */
/*   Updated: 2017/04/19 17:19:54 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_win(char *title, int width, int height, t_win *screen)
{
	screen->mlx = mlx_init();
	screen->win = mlx_new_window(screen->mlx, width, height, title);
}

void	draw_params(t_point *p1, t_point *p2, double *params)
{
	params[0] = fabs(p1->x - p2->x);
	params[1] = ((p1->x < p2->x) * 2) - 1;
	params[2] = fabs(p1->y - p2->y);
	params[3] = ((p1->y < p2->y) * 2) - 1;
	if (params[0] > params[2])
		params[4] = params[0] * 0.5;
	else
		params[4] = -params[2] * 0.5;
	params[6] = p1->color;
	params[7] = ((p1->color < p2->color) * 2) - 1;
}

void	draw_point(t_point *point, t_win *screen, int color)
{
	ft_memcpy(&(screen->img_addr[((int)(point->x) * 4) +
				((int)(point->y) * screen->size)]),
			&(color), (size_t)(sizeof(int)));
}

void	draw_line(t_point p1, t_point p2, t_win *screen)
{
	double	params[8];
	int		flag;

	draw_params(&p1, &p2, params);
	flag = 1;
	if (out_window(&p1) || out_window(&p2))
		while (flag && !((int)p1.x == (int)p2.x && (int)p1.y == (int)p2.y))
		{
			draw_point(&p1, screen, get_color(screen, (int)params[6], &p1));
			if (screen->scale)
				params[6] += (1 / screen->scale) * params[7];
			//draw_point(&p1, screen, get_color(&p1, &p2));
			params[5] = params[4];
			flag = 0;
			if (params[5] > -params[0] && (int)p1.x != (int)p2.x)
			{
				params[4] -= params[2];
				p1.x += params[1];
				flag = 1;
			}
			if (params[5] < params[2] && (int)p1.y != (int)p2.y)
			{
				params[4] += params[0];
				p1.y += params[3];
				flag = 1;
			}
		}
}

void	draw_map(t_win *scr)
{
	int		x;
	int		y;
	t_point	p1;

	y = 0;
	while (y < scr->map->len)
	{
		x = 0;
		while (x < (scr->map->lines[y]->len))
		{
			p1 = (*scr->map->lines[y]->points[x]);
			if (scr->map->lines[y]->points[x + 1])
				draw_line(p1, (*scr->map->lines[y]->points[x + 1]), scr);
			if (scr->map->lines[y + 1])
				if (scr->map->lines[y + 1]->points[x] &&
						x <= scr->map->lines[y + 1]->len)
					draw_line(p1, (*scr->map->lines[y + 1]->points[x]), scr);
			x++;
		}
		y++;
	}
}
