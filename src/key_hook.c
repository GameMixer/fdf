/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:13:39 by gderenzi          #+#    #+#             */
/*   Updated: 2017/04/27 13:56:09 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_hook_rotation(int keycode, t_win *screen)
{
	if (keycode == KEY_ROT_X_U)
		calc_rotation(screen, MOVE_ROT_X_U, 'x');
	else if (keycode == KEY_ROT_X_D)
		calc_rotation(screen, MOVE_ROT_X_D, 'x');
	else if (keycode == KEY_ROT_Y_U)
		calc_rotation(screen, MOVE_ROT_Y_U, 'y');
	else if (keycode == KEY_ROT_Y_D)
		calc_rotation(screen, MOVE_ROT_Y_D, 'y');
	else if (keycode == KEY_ROT_Z_U)
		calc_rotation(screen, MOVE_ROT_Z_U, 'z');
	else if (keycode == KEY_ROT_Z_D)
		calc_rotation(screen, MOVE_ROT_Z_D, 'z');
}

void	key_hook_shift(int keycode, t_win *screen)
{
	if (keycode == KEY_UP)
		calc_shift(screen, 0, MOVE_UP, 0);
	else if (keycode == KEY_DOWN)
		calc_shift(screen, 0, MOVE_DOWN, 0);
	else if (keycode == KEY_LEFT)
		calc_shift(screen, MOVE_LEFT, 0, 0);
	else if (keycode == KEY_RIGHT)
		calc_shift(screen, MOVE_RIGHT, 0, 0);
}

void	key_hook_scale(int keycode, t_win *screen)
{
	if (keycode == KEY_ZOOM_IN || keycode == KEY_ALT_ZOOM_IN)
	{
		screen->scale *= MOVE_ZOOM_IN;
		if (screen->scale < LIMIT_ZOOM_IN)
			calc_scale(screen, MOVE_ZOOM_IN);
		else
			screen->scale /= MOVE_ZOOM_IN;
	}
	else if (keycode == KEY_ZOOM_OUT || keycode == KEY_ALT_ZOOM_OUT)
	{
		screen->scale *= MOVE_ZOOM_OUT;
		if (screen->scale > LIMIT_ZOOM_OUT)
			calc_scale(screen, MOVE_ZOOM_OUT);
		else
			screen->scale /= MOVE_ZOOM_OUT;
	}
}

void	key_hook_color(int keycode, t_win *screen)
{
	if (keycode == KEY_COLOR_U)
	{
		if (screen->cnum < THEMES - 1)
			screen->cnum++;
		else
			screen->cnum = 0;
	}
	else if (keycode == KEY_COLOR_D)
	{
		if (screen->cnum > 0)
			screen->cnum--;
		else
			screen->cnum = THEMES - 1;
	}
}

int		key_hook(int keycode, t_win *screen)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(screen->mlx, screen->win);
		exit(0);
	}
	key_hook_rotation(keycode, screen);
	key_hook_shift(keycode, screen);
	key_hook_scale(keycode, screen);
	key_hook_color(keycode, screen);
	draw_reload(screen);
	return (0);
}
