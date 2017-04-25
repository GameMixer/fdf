/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 14:14:42 by gderenzi          #+#    #+#             */
/*   Updated: 2017/04/20 15:01:25 by gderenzi         ###   ########.fr       */
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

void	display_info(t_win *pic)
{
	display_controls(pic);
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
