/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:19:16 by gderenzi          #+#    #+#             */
/*   Updated: 2017/04/18 17:23:12 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>

# define SIZE_W 20
# define SIZE_H 20

# define WIN_W 1920
# define WIN_H 1080

/*
** Move pixel
*/
# define SHIFT_DIST 100
# define MOVE_UP -SHIFT_DIST
# define MOVE_DOWN SHIFT_DIST
# define MOVE_LEFT -SHIFT_DIST
# define MOVE_RIGHT SHIFT_DIST

# define ZOOM_AMOUNT 0.1
# define SCALE 1.0
# define MOVE_ZOOM_IN (SCALE + ZOOM_AMOUNT)
# define MOVE_ZOOM_OUT (SCALE - ZOOM_AMOUNT)

# define ROT_DEGREE 36
# define MOVE_ROT_X_U -M_PI / ROT_DEGREE
# define MOVE_ROT_X_D M_PI / ROT_DEGREE
# define MOVE_ROT_Y_U -M_PI / ROT_DEGREE
# define MOVE_ROT_Y_D M_PI / ROT_DEGREE
# define MOVE_ROT_Z_U -M_PI / ROT_DEGREE
# define MOVE_ROT_Z_D M_PI / ROT_DEGREE

/*
** Key codes
*/
# define KEY_ESC 53

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

# define KEY_ZOOM_IN 69
# define KEY_ALT_ZOOM_IN 24
# define KEY_ZOOM_OUT 78
# define KEY_ALT_ZOOM_OUT 27

# define KEY_ROT_X_U 1
# define KEY_ROT_X_D 13
# define KEY_ROT_Y_U 2
# define KEY_ROT_Y_D 0
# define KEY_ROT_Z_U 14
# define KEY_ROT_Z_D 12

/*
** Colors
*/
# define TEAL 0x6CD2A6
# define PURPLE 0xB200FF
# define BLUE 0x0041FF
# define BROWN 0xAD4F09
# define GREEN 0x25FF50
# define RED 0xDB3315
# define ORANGE 0xFFAF00
# define YELLOW 0xFFE819
# define WHITE 0xFFFFFF
# define GRAY 0x808080
# define BLACK 0x000000

typedef struct	s_color
{
	int			c1;
	int			c2;
}				t_color;

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_point;

typedef struct	s_line
{
	t_point		**points;
	int			len;
}				t_line;

typedef struct	s_map
{
	t_line		**lines;
	int			len;
	double		min;
	double		max;
	double		mid;
}				t_map;

typedef struct	s_window
{
	void		*mlx;
	void		*win;
	t_map		*map;
	void		*img;
	t_point		center;
	int			**color;
	int			cnum;
	char		*img_addr;
	int			bits;
	int			size;
	int			endian;
}				t_win;

typedef struct	s_matrix
{
	double		x1;
	double		x2;
	double		x3;
	double		x4;
	double		y1;
	double		y2;
	double		y3;
	double		y4;
	double		z1;
	double		z2;
	double		z3;
	double		z4;
}				t_matrix;

/*
**	Parse argument and create a map
**		parse_arg.c
*/
t_map			*ft_parse_map(char *av, int fd);
int				ft_row_num(char *map);
int				ft_points(char *line, int nb_line, t_point ***array_points);

/*
**	Draw the map
**		draw.c
*/
void			draw_win(char *title, int width, int height, t_win *screen);
void			draw_params(t_point *p1, t_point *p2, double *params);
void			draw_point(t_point *point, t_win *screen, int color);
void			draw_line(t_point p1, t_point p2, t_win *screen);
void			draw_map(t_win *screen);

/*
**	Make the map pretty with colors!!! Yay!!!
**		color.c
*/
void			get_min_max(t_map *map);
int				find_color(t_color *spectrum, int z, double min, double max);
int				get_color(t_win *screen, t_point *p1);
int				*put_color(int a, int b, int c);
int				**choose_color(void);

/*
** This is for when it detects a key has been pressed, and...
** ...does stuff with it.
** 	key_hook.c
*/
int				key_hook(int keycode, t_win *screen);
void			key_hook_rotation(int keycode, t_win *screen);
void			key_hook_shift(int keycode, t_win *screen);
void			key_hook_scale(int keycode, t_win *screen);

/*
** This to do MATHS!!!
** 	calc.c
*/
void			calc_point(t_point *p, t_matrix *m, t_win *screen);
void			calc_all_points(t_matrix *m, t_win *screen);
void			calc_rotation(t_win *screen, double rot, char axis);
void			calc_shift(t_win *screen, double x, double y, double z);
void			calc_scale(t_win *screen, double scale);

/*
**	Not the movie Matrix, but the math term Matrix, which is used to rotate
**	and change the map scale...Less exciting kind of Matrix...sorry.
**		matrix.c
*/
t_matrix		*matrix_rotation_x(double theta);
t_matrix		*matrix_rotation_y(double theta);
t_matrix		*matrix_rotation_z(double theta);
t_matrix		*matrix_shift(double tx, double ty, double tz);
t_matrix		*matrix_scale(double scale);

/*
**	Error display
**		error.c
*/
void			fdf_malloc_error(void);
void			fdf_map_error(void);
void			fdf_arg_error(void);

/*
**	Other functions that are in a file that I have very little imagination
**	to name it with, so it will stay this way. I'm not good with names...
**		util.c
*/
void			get_center(t_win *screen);
//int				get_color(t_point *p1, t_point *p2);
void			adapt_map(t_win *screen);
int				draw_reload(t_win *screen);
int				out_window(t_point *point);

#endif
