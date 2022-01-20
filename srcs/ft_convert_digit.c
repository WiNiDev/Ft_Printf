/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_digit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:43:23 by marvin            #+#    #+#             */
/*   Updated: 2021/11/21 14:46:48 by mberthoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

unsigned char	*ft_convers(unsigned int nbr)
{
	int				i;
	char			*s;
	unsigned char	*tmp;
	unsigned int	res;

	tmp = malloc(sizeof(char) * (ft_declen(nbr) + 1));
	if (!tmp)
		return (NULL);
	s = "0123456789abcdef";
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

int	ft_convert_hex(va_list *ap)
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
	tmp = ft_convers(nbr);
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

int	ft_convert_dec(va_list *ap)
{
	unsigned long int	nbr;
	int					i;

	i = 0;
	nbr = va_arg(*ap, long int);
	i = ft_putnbr(nbr);
	return (i);
}

int	ft_convert_unsdec(va_list *ap)
{
	unsigned int	nbr;
	int				i;

	i = 0;
	nbr = va_arg(*ap, unsigned int);
	i = ft_unsigned_putnbr(nbr);
	return (i);
}
