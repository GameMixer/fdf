/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 14:06:14 by gderenzi          #+#    #+#             */
/*   Updated: 2017/05/02 13:30:42 by gderenzi         ###   ########.fr       */
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
	if (ft_max(params[0], params[2]) > 1)
		params[5] = 1 / (double)(ft_max(params[0], params[2]) - 1);
	else if (ft_max(params[0], params[2]) == 1)
		params[5] = 1;
	else
		params[5] = 0;
	params[6] = 0;
}

void	draw_point(t_point *point, t_win *screen, int color)
{
	if (out_window(point) == 1)
	{
		ft_memcpy(&(screen->img_addr[((int)(point->x) * 4) +
					((int)(point->y) * screen->size)]),
				&(color), (size_t)(sizeof(int)));
	}
}

void	draw_line(t_point p1, t_point p2, t_win *screen)
{
	double	params[8];
	int		flag;

	draw_params(&p1, &p2, params);
	//printf("Params created...\n");
	flag = 1;
	if (out_window(&p1) || out_window(&p2))
		while (flag && !((int)p1.x == (int)p2.x && (int)p1.y == (int)p2.y))
		{
			draw_point(&p1, screen, get_color(screen, &p1, &p2, params[6]));
			//printf("Point (%d, %d) drawn...\n", (int)p1.x, (int)p1.y);
			params[6] += params[5];
			params[7] = params[4];
			flag = 0;
			if (params[7] > -params[0] && (int)p1.x != (int)p2.x)
			{
				params[4] -= params[2];
				p1.x += params[1];
				flag = 1;
			}
			if (params[7] < params[2] && (int)p1.y != (int)p2.y)
			{
				params[4] += params[0];
				p1.y += params[3];
				flag = 1;
			}
			//printf("End of loop. Moving to point (%d, %d)\n", (int)p1.x, (int)p1.y);
		}
	//printf("Point 1: (%d, %d)\n", (int)p1.x, (int)p1.y);
	//printf("Point 2: (%d, %d)\n", (int)p2.x, (int)p2.y);
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
			//printf("Drawing line %d from point %d...\n", y, x);
			//printf("(%f, %f, %f)\n", scr->map->lines[y]->points[x]->x, scr->map->lines[y]->points[x]->y, scr->map->lines[y]->points[x]->z);
			p1 = (*scr->map->lines[y]->points[x]);
			if (scr->map->lines[y]->points[x + 1])
			{
				//printf("to (%f, %f, %f)\n", scr->map->lines[y]->points[x+1]->x, scr->map->lines[y]->points[x+1]->y, scr->map->lines[y]->points[x+1]->z);
				draw_line(p1, (*scr->map->lines[y]->points[x + 1]), scr);
			}
			//printf("Testing to see if next line exists...\n");
			if (scr->map->lines[y + 1] && y + 1 < scr->map->len)
			{
				//printf("Testing to see if point below exists...\n");
				if (scr->map->lines[y + 1]->points[x] && x <= scr->map->lines[y + 1]->len) 
				{
					//printf("and (%f, %f, %f)\n", scr->map->lines[y+1]->points[x]->x, scr->map->lines[y+1]->points[x]->y, scr->map->lines[y+1]->points[x]->z);
					draw_line(p1, (*scr->map->lines[y + 1]->points[x]), scr);
				}
			}
			x++;
		}
		y++;
	}
}
