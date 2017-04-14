/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 18:08:59 by gderenzi          #+#    #+#             */
/*   Updated: 2017/04/13 16:21:18 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_controls(void)
{
	ft_putstr("\
____________________________\n\
CONTROLS:\n\
Translation:\n\
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
____________________________\n\
");	
}

int		main(int argc, char **argv)
{
	t_win	*screen;
	t_map	*map;

	if (argc == 2)
	{
		if (!(screen = (t_win *)malloc(sizeof(t_win))))
			fdf_malloc_error();
		map = ft_parse_map(argv[1], 0);
		if (map->len == 0 || map->lines[0]->len == 0)
			fdf_map_error();
		screen->map = map;
		get_center(screen);
		display_controls();
		draw_win("42 FDF", WIN_W, WIN_H, screen);
		//adapt_map(screen);
		mlx_expose_hook(screen->win, draw_reload, screen);
		mlx_hook(screen->win, 2, 3, key_hook, screen);
		mlx_loop(screen->mlx);
	}
	else
		fdf_arg_error();
	return (0);
}
