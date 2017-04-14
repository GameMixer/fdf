/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:35:43 by gderenzi          #+#    #+#             */
/*   Updated: 2017/03/06 13:04:00 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*begin;
	char	*pattern;
	size_t	i;

	i = 0;
	while (little[i] != '\0')
		i++;
	if (i == 0)
		return ((char *)big);
	while (*big)
	{
		begin = (char *)big;
		pattern = (char *)little;
		while (*big && *pattern && *big == *pattern)
		{
			big++;
			pattern++;
		}
		if (!*pattern)
			return (begin);
		big = begin + 1;
	}
	return (NULL);
}
