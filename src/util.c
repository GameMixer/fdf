/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 15:05:59 by gderenzi          #+#    #+#             */
/*   Updated: 2017/05/02 13:46:15 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*theme(int i)
{
	if (i == 0)
		return ("RGB");
	if (i == 1)
		return ("Black to white");
	if (i == 2)
		return ("Lava");
	if (i == 3)
		return ("Black to red");
	if (i == 4)
		return ("Island");
	if (i == 5)
		return ("Rouge");
	if (i == 6)
		return ("Hot and Cold");
	return ("Mountain");
}

void	get_center(t_win *screen)
{
	t_point	p;
	int		x;
	int		y;

	p = screen->center;
	y = screen->map->len;
	x = screen->map->lines[y - 1]->len;
	p.x = (screen->map->lines[y - 1]->points[x - 1]->x +
			screen->map->lines[0]->points[0]->x) / 2;
	p.y = (screen->map->lines[y - 1]->points[x - 1]->y +
			screen->map->lines[0]->points[0]->y) / 2;
	screen->center = p;
}

int		draw_reload(t_win *screen)
{
	screen->img = mlx_new_image(screen->mlx, WIN_W + 100, WIN_H + 100);
	screen->img_addr = mlx_get_data_addr(screen->img,
			&(screen->bits), &(screen->size), &(screen->endian));
	draw_map(screen);
	mlx_put_image_to_window(screen->mlx, screen->win, screen->img, 0, 0);
	display_info(screen);
	mlx_destroy_image(screen->mlx, screen->img);
	return (0);
}

void	adapt_map(t_win *screen)
{
	int		w;
	int		h;
	double	s;

	w = (WIN_W) / 2;
	h = (WIN_H) / 2;
	if (screen->center.x == 0)
		screen->center.x = 10;
	if (screen->center.y == 0)
		screen->center.y = 10;
	if (((screen->center.y) / (screen->center.x)) <= (WIN_H / WIN_W))
		s = w / (screen->center.x);
	else
		s = h / (screen->center.y);
	calc_shift(screen, -screen->center.x + w, -screen->center.y + h, 0);
	calc_scale(screen, s);
	calc_rotation(screen, M_PI / 15, 'z');
	calc_rotation(screen, M_PI / 5, 'x');
	screen->scale = s;
}

int		out_window(t_point *point)
{
	if (!(point->x > WIN_W + SHIFT_DIST || point->x <= 0 ||
				point->y > WIN_H + SHIFT_DIST || point->y <= 0))
		return (1);
	else
		return (0);
}
