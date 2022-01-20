/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_scnd_digit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:49:02 by marvin            #+#    #+#             */
/*   Updated: 2021/11/21 14:47:01 by mberthoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

unsigned char	*ft_upper_convers(unsigned int nbr)
{
	int				i;
	char			*s;
	unsigned char	*tmp;
	unsigned int	res;

	tmp = malloc(sizeof(char) * (ft_declen(nbr) + 1));
	if (!tmp)
		return (NULL);
	s = "0123456789ABCDEF";
	res = 0;
	i = 0;
	while (nbr)
	{
		res = nbr % 16;
		nbr = nbr / 16;
		tmp[i] = s[res];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int	ft_convert_upperhex(va_list *ap)
{
	unsigned int	nbr;
	unsigned char	*tmp;
	int				i;
	int				e;

	i = 0;
	e = 0;
	nbr = va_arg(*ap, unsigned int);
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	tmp = ft_upper_convers(nbr);
	i = ft_strlen(tmp);
	e = i;
	e--;
	while (e >= 0)
	{
		write(1, &tmp[e], 1);
		e--;
	}
	free(tmp);
	return (i);
}

int	ft_convert_void(va_list *ap)
{
	unsigned long long	nbr;
	unsigned long long	result;
	unsigned long long	res;
	int					i;

	i = 0;
	nbr = va_arg(*ap, unsigned long long);
	result = nbr;
	if (nbr == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	while (result > 0)
	{
		res = result % 16;
		result = result / 16;
		i++;
	}
	i += ft_putnbr_void(nbr);
	i += 2;
	return (i);
}
