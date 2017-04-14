/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:07:38 by gderenzi          #+#    #+#             */
/*   Updated: 2017/03/03 15:23:59 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*newsrc;
	char	*newdest;
	size_t	i;

	i = 0;
	newsrc = (char *)src;
	newdest = (char *)dst;
	if (newsrc < newdest)
		while ((int)(--len) >= 0)
			*(newdest + len) = *(newsrc + len);
	else
		while (i < len)
		{
			*(newdest + i) = *(newsrc + i);
			i++;
		}
	return (dst);
}
