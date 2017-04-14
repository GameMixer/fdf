/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:50:12 by gderenzi          #+#    #+#             */
/*   Updated: 2017/03/02 12:23:20 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t dlen;
	size_t slen;

	i = 0;
	j = 0;
	dlen = 0;
	slen = 0;
	while (dst[dlen] != '\0')
		dlen++;
	while (src[slen] != '\0')
		slen++;
	if (dlen >= size)
		return (slen + size);
	while (dst[i] != '\0' && i < size - 1)
		i++;
	while (src[j] != '\0' && i < (size - 1))
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dlen + slen);
}
