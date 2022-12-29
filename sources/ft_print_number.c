/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:57:36 by bgresse           #+#    #+#             */
/*   Updated: 2022/12/29 05:53:14 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr(int number, t_print *tab)
{
	unsigned char	*string;

	string = ft_itoa(number);
	if ((tab->point == 1 || tab->zero == 1) && string[0] == '-')
		ft_putstr(string + 1, tab);
	else
		ft_putstr(string, tab);
	free(string);
}

void	ft_zero_flags(t_print *tab, int ret, unsigned char *string)
{
	if (ret < 0)
		ft_putchar('-', tab);
	if (tab->plus == 1)
		tab->precision--;
	while (tab->precision-- > (int)ft_strlen((char *)string))
		ft_putchar('0', tab);
}

void	ft_point_flags(t_print *tab, int ret, unsigned char *string)
{
	if (ret < 0)
	{
		ft_putchar('-', tab);
		tab->precision++;
	}
	while (tab->precision-- > (int)ft_strlen((char *)string))
		ft_putchar('0', tab);
}

void	ft_dash_flags(t_print *tab, int ret, unsigned char *string)
{
	ft_putnbr(ret, tab);
	while (tab->precision-- > (int)ft_strlen((char *)string))
		ft_putchar(' ', tab);
}

void	ft_print_number(t_print *tab)
{
	int		ret;
	unsigned char	*string;

	ret = va_arg(tab->args, int);
	string = ft_itoa(ret);
	if (tab->space == 1 && ret >= 0)
		ft_putchar(' ', tab);
	if (string[0] == '-')
		tab->plus = 0;
	if (tab->plus == 1)
		ft_putchar('+', tab);
	if (tab->point == 1)
		ft_point_flags(tab, ret, string);
	if (tab->zero == 1)
		ft_zero_flags(tab, ret, string);
	else if (tab->dash == 1)
	{
		ft_dash_flags(tab, ret, string);
		return (free(string));
	}
	ft_putnbr(ret, tab);
	free(string);
}
