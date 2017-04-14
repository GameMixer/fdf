/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:37:05 by gderenzi          #+#    #+#             */
/*   Updated: 2017/03/03 14:34:48 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*begin;
	char	*pattern;
	size_t	i;
	size_t	j;

	if (ft_strlen((char *)little) == 0)
		return ((char *)big);
	i = 0;
	while (*big && i < len)
	{
		j = i - 1;
		begin = (char *)big;
		pattern = (char *)little;
		while (*big && *pattern && *big == *pattern && ++j < len)
		{
			big++;
			pattern++;
		}
		if (!*pattern)
			return (begin);
		big = begin + 1;
		i++;
	}
	return (NULL);
}
