/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 20:00:57 by gderenzi          #+#    #+#             */
/*   Updated: 2017/03/07 11:45:15 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fill(int count, int space)
{
	while (count < 16)
	{
		ft_putchar(' ');
		ft_putchar(' ');
		if (space && count % space == space - 1)
			ft_putchar(' ');
		count++;
	}
}

static int	ft_putnbrhex(size_t nb, unsigned int len, int upper)
{
	char	nb_act;
	int		size;

	nb_act = nb % 16;
	size = 1;
	if (nb >= 16 && len > 0)
		size += ft_putnbrhex(nb / 16, len - 1, upper);
	else if (nb >= 16 && len <= 0)
		size += ft_putnbrhex(nb / 16, 0, upper);
	else if (len > 0)
	{
		size += len - 1;
		while (--len > 0)
			ft_putchar('0');
	}
	if (upper)
		ft_putchar(HEXB_UP[(int)nb_act]);
	else
		ft_putchar(HEXB_LOW[(int)nb_act]);
	return (size);
}

static void	ft_putnstr_hex(char *str, size_t len, int hex, int space)
{
	size_t	i;

	i = 0;
	while (len > i)
	{
		if (hex)
		{
			ft_putchar(HEXB_LOW[(int)((unsigned char)str[i] / 16)]);
			ft_putchar(HEXB_LOW[(int)((unsigned char)str[i] % 16)]);
		}
		else if (str[i] < 127 && str[i] >= 31)
			ft_putchar(str[i]);
		else
			ft_putchar('.');
		if (space && (int)i % space == space - 1)
			ft_putchar(' ');
		i++;
	}
	if (hex)
		ft_fill(i, space);
}

static void	ft_putline(char *addr, size_t offset, size_t size)
{
	ft_putnbrhex(offset, 8, 0);
	ft_putchar(':');
	ft_putchar('\t');
	ft_putnstr_hex(addr + offset, size, 1, 2);
	ft_putchar('\t');
	ft_putnstr_hex(addr + offset, size, 0, 0);
	ft_putchar('\n');
}

void		*ft_print_memory(void *addr, size_t size)
{
	size_t	count;

	count = 0;
	while (size - 16 > count && size - 16 > 0)
	{
		ft_putline(addr, count, 16);
		count += 16;
	}
	if (size - count > 0)
		ft_putline(addr, count, size - count);
	return (addr);
}
