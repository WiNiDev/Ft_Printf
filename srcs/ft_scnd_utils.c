/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scnd_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 00:18:13 by marvin            #+#    #+#             */
/*   Updated: 2021/11/21 14:47:21 by mberthoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_strlen(unsigned char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_declen(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int	ft_putnbr_void(unsigned long long n)
{
	char	*s;

	s = "0123456789abcdef";
	if (n >= 16)
	{
		ft_putnbr_void(n / 16);
		ft_putchar(s[n % 16]);
	}
	if (n > 0 && n < 16)
		ft_putchar(s[n]);
	return (0);
}
