/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:21:35 by gderenzi          #+#    #+#             */
/*   Updated: 2017/03/09 16:45:22 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int value, int base)
{
	int		i;
	int		neg;
	char	*nbr;

	i = 1;
	neg = 0;
	if (value < 0 && base == 10)
		neg = 1;
	value *= (value < 0) * -2 + 1;
	while (ft_pow(base, i) - 1 < value)
		i++;
	if (!(nbr = (char *)malloc(sizeof(nbr) * i)))
		return (NULL);
	nbr[i + neg] = '\0';
	while (i-- > 0)
	{
		if (value % base > 9)
			nbr[i + neg] = (value % base) + 'A' + 10;
		else
			nbr[i + neg] = (value % base) + '0';
		value = value / base;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}
