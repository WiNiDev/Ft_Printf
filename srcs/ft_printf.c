/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:14:39 by marvin            #+#    #+#             */
/*   Updated: 2021/11/21 14:46:04 by mberthoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	check_symb(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	convert_arg(va_list *ap, char c, ...)
{
	int	value;

	value = 0;
	if (c == 'c')
		value += ft_print_char(ap);
	else if (c == '%')
		value += ft_print_div();
	else if (c == 's')
		value += ft_print_string(ap);
	else if (c == 'x')
		value += ft_convert_hex(ap);
	else if (c == 'i' || c == 'd')
		value += ft_convert_dec(ap);
	else if (c == 'u')
		value += ft_convert_unsdec(ap);
	else if (c == 'X')
		value += ft_convert_upperhex(ap);
	else if (c == 'p')
		value += ft_convert_void(ap);
	return (value);
}

int	ft_printf(const char *str, ...)
{
	int		value;
	int		i;
	va_list	ap;

	va_start(ap, str);
	i = -1;
	value = 0;
	while (str[++i])
	{
		if (str[i] == '%' && check_symb(str[i + 1]) == 1)
			value += convert_arg(&ap, str[i++ + 1]);
		else if (str[i] == '\n')
		{
			write(1, "\n", 1);
			value++;
		}
		else
		{
			write(1, &str[i], 1);
			value++;
		}
	}
	va_end(ap);
	return (value);
}
