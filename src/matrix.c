/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:26:37 by gderenzi          #+#    #+#             */
/*   Updated: 2017/04/17 15:58:13 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*matrix_rotation_x(double theta)
{
	t_matrix	*m;

	if (!(m = (t_matrix *)ft_memalloc(sizeof(t_matrix))))
		fdf_malloc_error();
	m->x1 = 1;
	m->y2 = cos(theta);
	m->y3 = -sin(theta);
	m->z2 = sin(theta);
	m->z3 = cos(theta);
	return (m);
}

t_matrix	*matrix_rotation_y(double theta)
{
	t_matrix	*m;

	if (!(m = (t_matrix *)ft_memalloc(sizeof(t_matrix))))
		fdf_malloc_error();
	m->x1 = cos(theta);
	m->x3 = sin(theta);
	m->y2 = 1;
	m->z1 = -sin(theta);
	m->z3 = cos(theta);
	return (m);
}

t_matrix	*matrix_rotation_z(double theta)
{
	t_matrix	*m;

	if (!(m = (t_matrix *)ft_memalloc(sizeof(t_matrix))))
		fdf_malloc_error();
	m->x1 = cos(theta);
	m->x2 = -sin(theta);
	m->y1 = sin(theta);
	m->y2 = cos(theta);
	m->z3 = 1;
	return (m);
}

t_matrix	*matrix_shift(double tx, double ty, double tz)
{
	t_matrix	*m;

	if (!(m = (t_matrix *)ft_memalloc(sizeof(t_matrix))))
		fdf_malloc_error();
	m->x4 = tx;
	m->y4 = ty;
	m->z4 = tz;
	m->x1 = 1;
	m->y2 = 1;
	m->z3 = 1;
	return (m);
}

t_matrix	*matrix_scale(double scale)
{
	t_matrix	*m;

	if (!(m = (t_matrix *)ft_memalloc(sizeof(t_matrix))))
		fdf_malloc_error();
	m->x1 = scale;
	m->y2 = scale;
	m->z3 = scale;
	return (m);
}
