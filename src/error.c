/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:32:14 by gderenzi          #+#    #+#             */
/*   Updated: 2017/04/07 13:52:52 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_malloc_error(void)
{
	ft_putstr("malloc error\n");
	exit(1);
}

void	fdf_map_error(void)
{
	ft_putstr("map error\n");
	exit(2);
}

void	fdf_arg_error(void)
{
	ft_putstr("Only one argument can be taken into account.\n");
	exit(3);
}
