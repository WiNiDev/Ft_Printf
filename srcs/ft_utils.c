/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 00:18:23 by marvin            #+#    #+#             */
/*   Updated: 2021/11/21 14:46:22 by mberthoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_nblen(long int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		i++;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long int	nb;
	int			i;

	nb = n;
	i = ft_nblen(n);
	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
	if (nb > 0 && nb < 10)
		ft_putchar(nb + '0');
	return (i);
}

int	ft_uslen(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		i++;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_unsigned_putnbr(unsigned int n)
{
	int	i;

	i = ft_uslen(n);
	if (n == 0)
		write(1, "0", 1);
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
	if (n > 0 && n < 10)
		ft_putchar(n + '0');
	return (i);
}
