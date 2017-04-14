/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:46:17 by gderenzi          #+#    #+#             */
/*   Updated: 2017/04/13 16:31:15 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calc_point(t_point *p, t_matrix *m, t_win *screen)
{
	double	tmp_x;
	double	tmp_y;
	double	tmp_z;

	p->x -= screen->center.x;
	p->y -= screen->center.y;
	tmp_x = p->x * m->x1 + p->y * m->x2 + p->z * m->x3 + m->x4;
	tmp_y = p->x * m->y1 + p->y * m->y2 + p->z * m->y3 + m->y4;
	tmp_z = p->x * m->z1 + p->y * m->z2 + p->z * m->z3 + m->z4;
	p->x = tmp_x;
	p->y = tmp_y;
	p->z = tmp_z;
	p->x += screen->center.x;
	p->y += screen->center.y;
}

void	calc_all_points(t_matrix *m, t_win *screen)
{
	int	x;
	int	y;

	y = 0;
	while (y < screen->map->len)
	{
		x = 0;
		while (x < (screen->map->lines[y]->len))
		{
			calc_point(screen->map->lines[y]->points[x], m, screen);
			x++;
		}
		y++;
	}
}

void	calc_rotation(t_win *screen, double rot, char axis)
{
	t_matrix	*m_rot;

	if (axis == 'x')
		m_rot = matrix_rotation_x(rot);
	else if (axis == 'y')
		m_rot = matrix_rotation_y(rot);
	else
		m_rot = matrix_rotation_z(rot);
	calc_all_points(m_rot, screen);
	free(m_rot);
}

void	calc_shift(t_win *screen, double x, double y, double z)
{
	t_matrix	*m_shift;

	m_shift = matrix_shift(x, y, z);
	calc_all_points(m_shift, screen);
	get_center(screen);
	free(m_shift);
}

void	calc_scale(t_win *screen, double scale)
{
	t_matrix	*m_scale;

	m_scale = matrix_scale(scale);
	calc_all_points(m_scale, screen);
	free(m_scale);
}
