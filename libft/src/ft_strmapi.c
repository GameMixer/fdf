/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:25:26 by gderenzi          #+#    #+#             */
/*   Updated: 2017/03/02 16:29:01 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		newstr = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1);
		if (!newstr)
			return (NULL);
		while (s[i] != '\0')
		{
			newstr[i] = (*f)(i, s[i]);
			i++;
		}
		newstr[i] = '\0';
		return (newstr);
	}
	return (NULL);
}
