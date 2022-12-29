/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 05:03:36 by bgresse           #+#    #+#             */
/*   Updated: 2022/12/29 05:25:43 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_base_adress(t_print *tab, unsigned long number, char *base)
{
	size_t		base_len;

	base_len = ft_strlen(base);
	if (number >= base_len)
	{
		ft_putnbr_base(tab, number / base_len, base);
	}
	ft_putchar(base[number % base_len], tab);
}

void    ft_print_adress(t_print *tab)
{
    unsigned long ret;

    ret = va_arg(tab->args, unsigned long);
    ft_putstr((unsigned char *)"0x", tab);
    ft_putnbr_base_adress(tab, ret, "0123456789abcdef");
}