/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 18:08:59 by gderenzi          #+#    #+#             */
/*   Updated: 2017/04/27 13:21:20 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_win	*screen;
	t_map	*map;

	if (argc == 2)
	{
		if (!(screen = (t_win *)malloc(sizeof(t_win))))
			fdf_malloc_error();
		printf("Memory allocated. Parsing map...\n");
		map = ft_parse_map(argv[1], 0);
		if (map->len == 0 || map->lines[0]->len == 0)
			fdf_map_error();
		printf("Map created. Choosing color...\n");
		screen->map = map;
		get_center(screen);
		screen->color = choose_color();
		screen->cnum = 0;
		printf("Color chosen. Displaying window...\n");
		draw_win("42 FDF", WIN_W, WIN_H, screen);
		printf("Window displayed. Adapting map...\n");
		adapt_map(screen);
		printf("Map adapted. If it fails after this, youre screwed...\n");
		mlx_expose_hook(screen->win, draw_reload, screen);
		printf("Running draw_reload...\n");
		mlx_hook(screen->win, 2, 3, key_hook, screen);
		printf("Running key_hook...\n");
		mlx_loop(screen->mlx);
	}
	else
		fdf_arg_error();
	return (0);
}
