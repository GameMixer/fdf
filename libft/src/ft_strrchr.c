/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:04:54 by gderenzi          #+#    #+#             */
/*   Updated: 2017/03/02 12:29:22 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	int		found;

	temp = (char *)s;
	found = 0;
	while (*s != '\0')
	{
		if (*s == c)
		{
			temp = (char *)s;
			found = 1;
		}
		s++;
	}
	if (found)
		return (temp);
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
