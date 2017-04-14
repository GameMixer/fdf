/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:16:33 by gderenzi          #+#    #+#             */
/*   Updated: 2017/03/02 16:28:47 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	int		i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		newstr = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1);
		if (!newstr)
			return (NULL);
		while (s[i] != '\0')
		{
			newstr[i] = (*f)(s[i]);
			i++;
		}
		newstr[i] = '\0';
		return (newstr);
	}
	return (NULL);
}
