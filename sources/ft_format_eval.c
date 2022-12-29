/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_eval.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:58:25 by bgresse           #+#    #+#             */
/*   Updated: 2022/12/29 05:22:46 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_format_eval(t_print *tab, const char *format, int index)
{
	index = ft_format_flags(tab, format, index);
	if (format[index] == 'c')
		ft_print_char(tab);
	if (format[index] == 's')
		ft_print_string(tab);
	if (format[index] == 'd' || format[index] == 'i')
		ft_print_number(tab);
	if (format[index] == 'u')
		ft_print_hexa(tab, "0123456789");
	if (format[index] == 'x')
		ft_print_hexa(tab, "0123456789abcdef");
	if (format[index] == 'X')
		ft_print_hexa(tab, "0123456789ABCDEF");
	if (format[index] == 'p')
		ft_print_adress(tab);
	if (format[index] == '%')
		ft_putchar('%', tab);
	return (index);
}
