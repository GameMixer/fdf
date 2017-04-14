/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:40:11 by gderenzi          #+#    #+#             */
/*   Updated: 2017/03/03 14:19:58 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*newsrc;
	unsigned char	*newdest;
	size_t			i;

	newsrc = (unsigned char *)src;
	newdest = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		newdest[i] = newsrc[i];
		if (newsrc[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
