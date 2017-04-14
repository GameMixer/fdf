/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:52:14 by gderenzi          #+#    #+#             */
/*   Updated: 2017/03/02 16:45:51 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*result;

	if (s1 && s2)
	{
		i = 0;
		j = 0;
		len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
		if ((result = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		while (s1[j] != '\0')
		{
			result[i++] = s1[j++];
		}
		j = 0;
		while (s2[j] != '\0')
		{
			result[i++] = s2[j++];
		}
		result[i] = '\0';
		return (result);
	}
	return (NULL);
}
