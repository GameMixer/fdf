/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:52:14 by gderenzi          #+#    #+#             */
/*   Updated: 2017/03/02 16:45:51 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_char(char const *s1, char c)
{
	char	*newstr;
	size_t	i;
	size_t	len;

	if (!s1 || !c)
		return (NULL);
	len = ft_strlen(s1);
	newstr = ft_strnew(len + 1);
	if (!newstr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(newstr + i) = *(s1 + i);
		i++;
	}
	*(newstr + i) = c;
	return (newstr);
}
