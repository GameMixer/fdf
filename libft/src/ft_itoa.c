/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:52:53 by gderenzi          #+#    #+#             */
/*   Updated: 2017/03/06 19:52:32 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	size_t	i;
	int		sign;
	char	*str;

	sign = (n < 0) * -2 + 1;
	i = ft_countdigits(n);
	i += (n < 0);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n = sign * n;
	if ((str = (char *)malloc(sizeof(char) * i + 1)) == NULL)
		return (NULL);
	i = 0;
	str[i] = (n % 10) + '0';
	i++;
	while (n /= 10)
		str[i++] = (n % 10) + '0';
	if (sign == -1)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
