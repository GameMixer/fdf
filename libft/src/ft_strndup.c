/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:51:33 by gderenzi          #+#    #+#             */
/*   Updated: 2017/03/07 16:25:54 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*result;
	char	*newsrc;
	char	*dest;
	size_t	i;

	i = 0;
	newsrc = (char *)src;
	if ((result = (char *)malloc(sizeof(*src) * (n + 1))) == NULL)
		return (NULL);
	dest = result;
	while (*newsrc != '\0' && i < n)
	{
		*dest = *newsrc;
		dest++;
		newsrc++;
		i++;
	}
	*dest = '\0';
	return (result);
}
