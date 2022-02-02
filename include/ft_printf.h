/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:57:48 by marvin            #+#    #+#             */
/*   Updated: 2021/11/21 14:06:17 by mberthoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_putnbr(int n);
int		ft_strlen(unsigned char *str);
int		ft_declen(unsigned int nb);
int		ft_unsigned_putnbr(unsigned int n);
int		ft_putnbr_void(unsigned long long n);
int		ft_print_char(va_list *ap);
int		ft_print_div(void);
int		ft_print_string(va_list *ap);
int		ft_convert_hex(va_list *ap);
int		ft_convert_dec(va_list *ap);
int		ft_convert_unsdec(va_list *ap);
int		ft_convert_upperhex(va_list *ap);
int		ft_convert_void(va_list *ap);
void	ft_putchar(char c);

#endif
