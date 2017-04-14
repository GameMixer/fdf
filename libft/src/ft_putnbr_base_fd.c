/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:54:14 by gderenzi          #+#    #+#             */
/*   Updated: 2017/03/09 16:56:37 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_fd(int n, int base, int fd)
{
	if (n < 0 && base == 10)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= base)
	{
		ft_putnbr_base_fd(n / base, base, fd);
		ft_putnbr_base_fd(n % base, base, fd);
	}
	else if (n >= 10)
		ft_putchar_fd(n + 'A' - 10, fd);
	else
		ft_putchar_fd(n + '0', fd);
}
