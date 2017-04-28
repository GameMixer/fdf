/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 14:14:42 by gderenzi          #+#    #+#             */
/*   Updated: 2017/04/27 15:22:36 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_controls(t_win *pic)
{
	mlx_string_put(pic->mlx, pic->win, 10, 10,
			pic->color[pic->cnum][1], "=============CONTROLS=============");
	mlx_string_put(pic->mlx, pic->win, 10, 22,
			pic->color[pic->cnum][1], "Shifting/Moving:");
	mlx_string_put(pic->mlx, pic->win, 70, 34,
			pic->color[pic->cnum][1], "Arrow Keys: UP, DOWN, LEFT, RIGHT");
	mlx_string_put(pic->mlx, pic->win, 10, 58,
			pic->color[pic->cnum][1], "Rotation:");
	mlx_string_put(pic->mlx, pic->win, 70, 70,
			pic->color[pic->cnum][1], "X: A, D");
	mlx_string_put(pic->mlx, pic->win, 70, 82,
			pic->color[pic->cnum][1], "Y: S, W");
	mlx_string_put(pic->mlx, pic->win, 70, 94,
			pic->color[pic->cnum][1], "Z: Q, E");
	mlx_string_put(pic->mlx, pic->win, 10, 118,
			pic->color[pic->cnum][1], "Zoom:");
	mlx_string_put(pic->mlx, pic->win, 70, 130,
			pic->color[pic->cnum][1], "IN/OUT: +/-");
	mlx_string_put(pic->mlx, pic->win, 10, 154,
			pic->color[pic->cnum][1], "Change Themes:");
	mlx_string_put(pic->mlx, pic->win, 70, 166,
			pic->color[pic->cnum][1], "PREV/NEXT: </>");
	mlx_string_put(pic->mlx, pic->win, 10, 178,
			pic->color[pic->cnum][1], "===========ESC TO QUIT============");
/*
	return("\
____________________________\n\
CONTROLS:\n\
Shifting/Moving:\n\
	Y: Key: UP, DOWN\n\
	X: Key: LEFT, RIGHT\n\
\n\
Rotation:\n\
	X: A, D\n\
	Y: S, W\n\
	Z: Q, E\n\
\n\
Zoom:\n\
	IN: Keypad: +\n\
	OUT: Keypad: -\n\
\n\
Change Themes:\n\
	NEXT: >\n\
	PREV: <\n\
\n\
ESC to Quit\n\
____________________________\n\
");
*/
}

void	display_fill(t_win *pic, t_color *spectrum, int z, double bound)
{
	int		x;
	int		color;
	int		limit;
	double	alpha;

	alpha = 0;
	limit = z + (SPEC_H / 2);
	while (z <= limit)
	{
		x = 0;
		if ((pic->map->mid) > bound)
			color = find_color(spectrum, ((bound * (1 - alpha)) +
						(pic->map->mid * alpha)), bound, pic->map->mid);
		else
			color = find_color(spectrum, ((pic->map->mid * (1 - alpha)) +
						(bound * alpha)), pic->map->mid, bound);
		while (x < SPEC_W)
		{
			mlx_pixel_put(pic->mlx, pic->win, x + 420, SPEC_H + 10 - z, color);
			x++;
		}
		alpha += 1.0 / ((SPEC_H / 2) - 1);
		z++;
	}
}

void	display_spectrum(t_win *pic)
{
	int		z;
	t_color	c;

	z = 0;
	c.c1 = pic->color[pic->cnum][0];
	c.c2 = pic->color[pic->cnum][1];
	display_fill(pic, &c, z, pic->map->min);
	c.c1 = pic->color[pic->cnum][1];
	c.c2 = pic->color[pic->cnum][2];
	display_fill(pic, &c, z + (SPEC_H / 2), pic->map->max);
	mlx_string_put(pic->mlx, pic->win, 432 + SPEC_W, 10,
			pic->color[pic->cnum][2], "MAX: ");
	mlx_string_put(pic->mlx, pic->win, 492 + SPEC_W, 10,
			pic->color[pic->cnum][2], ft_itoa(pic->map->max));
	mlx_string_put(pic->mlx, pic->win, 432 + SPEC_W, SPEC_H - 2,
			pic->color[pic->cnum][0], "MIN: ");
	mlx_string_put(pic->mlx, pic->win, 492 + SPEC_W, SPEC_H - 2,
			pic->color[pic->cnum][0], ft_itoa(pic->map->min));
}

void	display_info(t_win *pic)
{
	display_controls(pic);
	display_spectrum(pic);
	mlx_string_put(pic->mlx, pic->win, 10, WIN_H - 59,
			pic->color[pic->cnum][1], "MIN   : ");
	mlx_string_put(pic->mlx, pic->win, 94, WIN_H - 59,
			pic->color[pic->cnum][1], ft_itoa(pic->map->min));
	mlx_string_put(pic->mlx, pic->win, 10, WIN_H - 47,
			pic->color[pic->cnum][1], "MAX   : ");
	mlx_string_put(pic->mlx, pic->win, 94, WIN_H - 47,
			pic->color[pic->cnum][1], ft_itoa(pic->map->max));
	mlx_string_put(pic->mlx, pic->win, 10, WIN_H - 35,
			pic->color[pic->cnum][1], "Center: ");
	mlx_string_put(pic->mlx, pic->win, 94, WIN_H - 35,
			pic->color[pic->cnum][1], ft_itoa((int)pic->center.x));
	mlx_string_put(pic->mlx, pic->win, 94 + (ft_countdigits((int)pic->center.x)
				* 10), WIN_H - 35, pic->color[pic->cnum][1], ", ");
	mlx_string_put(pic->mlx, pic->win, 114 + (ft_countdigits((int)pic->center.x)
				* 10), WIN_H - 35, pic->color[pic->cnum][1],
			ft_itoa((int)pic->center.y));
	mlx_string_put(pic->mlx, pic->win, 10, WIN_H - 23,
			pic->color[pic->cnum][1], "Theme: ");
	mlx_string_put(pic->mlx, pic->win, 94, WIN_H - 23,
			pic->color[pic->cnum][1], theme(pic->cnum));
}
