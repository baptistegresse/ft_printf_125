/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:54:28 by bgresse           #+#    #+#             */
/*   Updated: 2022/12/29 06:07:13 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_get_precision(t_print *tab, const char *format, int index)
{
	unsigned char	*numbers;
	int		index_numbers;

	index_numbers = index;
	while (ft_isdigit(format[index_numbers]))
		index_numbers++;
	numbers = malloc(sizeof(char) * (index_numbers - index + 1));
	if (!numbers)
		return (0);
	index_numbers = 0;
	while (ft_isdigit(format[index]))
		numbers[index_numbers++] = format[index++];
	numbers[index_numbers] = 0;
	tab->precision = ft_atoi((char *)numbers);
	free(numbers);
	return (index - 1);
}

int	ft_format_flags(t_print *tab, const char *format, int index)
{
	while (format[index] != 'c' && format[index] != 's' && format[index] != 'd'
		&& format[index] != 'i' && format[index] != 'u' && format[index] != 'x'
		&& format[index] != 'X' && format[index] != 'p' && format[index] != '%')
	{
		if (format[index] == '#')
			tab->sharp = 1;
		if (format[index] == '0')
			tab->zero = 1;
		if (format[index] == '.')
			tab->point = 1;
		if (format[index] == '-')
			tab->dash = 1;
		if (format[index] == '+')
			tab->plus = 1;
		if (format[index] == ' ')
			tab->space = 1;
		if (format[index] >= '1' && format[index] <= '9')
			index = ft_get_precision(tab, format, index);
		index++;
	}
	return (index);
}
