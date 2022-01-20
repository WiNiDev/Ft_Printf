/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:36:44 by marvin            #+#    #+#             */
/*   Updated: 2021/11/21 14:46:35 by mberthoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_char(va_list *ap)
{
	char	c;

	c = va_arg(*ap, int);
	write(1, &c, 1);
	return (1);
}

int	ft_print_div(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_print_string(va_list *ap)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(*ap, char *);
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}
