/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:54:25 by bgresse           #+#    #+#             */
/*   Updated: 2022/12/29 06:33:20 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	init_tab(t_print *tab)
{
	tab->point = 0;
	tab->dash = 0;
	tab->precision = 0;
	tab->zero = 0;
	tab->len = 0;
	tab->plus = 0;
	tab->space = 0;
	tab->sharp = 0;
	tab->width = 0;
}

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	size_t	index;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (0);
	init_tab(tab);
	va_start(tab->args, format);
	index = -1;
	while (format[++index])
	{
		if (format[index] == '%')
			index = ft_format_eval(tab, format, index + 1);
		else
			ft_putchar(format[index], tab);
	}
	va_end(tab->args);
	return (free(tab), tab->len);
}
