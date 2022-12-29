/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 03:01:06 by bgresse           #+#    #+#             */
/*   Updated: 2022/12/29 06:44:55 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_base(t_print *tab, unsigned int number, char *base)
{
	size_t		base_len;

	base_len = ft_strlen(base);
	if (number >= base_len)
	{
		ft_putnbr_base(tab, number / base_len, base);
	}
	ft_putchar(base[number % base_len], tab);
}

void	ft_get_size(unsigned int ret, char *base, t_print *tab)
{
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (ret >= base_len)
	{
		ft_putnbr_base(tab, ret / base_len, base);
	}
	tab->width++;
}
void	ft_zero_flags_hexa(t_print *tab, unsigned int ret, char *base)
{
	ft_get_size(ret, base, tab);
	while (tab->precision-- > tab->width)
		ft_putchar('0', tab);
}

void	ft_point_flags_hexa(t_print *tab, unsigned int ret, char *base)
{
	ft_get_size(ret, base, tab);
	while (tab->precision-- > tab->width)
		ft_putchar('0', tab);
}


void	ft_dash_flags_hexa(t_print *tab, unsigned int ret, char *base)
{
	ft_get_size(ret, base, tab);
	ft_putnbr_base(tab, ret, base);
	while (tab->precision-- > tab->width)
		ft_putchar(' ', tab);
}

void	ft_print_hexa(t_print *tab, char *base)
{
	unsigned int 	ret;
	unsigned char	*string;

	ret = va_arg(tab->args, unsigned int);
	string = ft_uitoh(ret);
	if (tab->sharp == 1 && ret > 0)
	{
		if (base[10] == 'A')
			ft_putstr((unsigned char *)"0X", tab);
		else
			ft_putstr((unsigned char *)"0x", tab);
	}		
	if (tab->point == 1)
		ft_point_flags_hexa(tab, ret, base);
	if (tab->zero == 1)
		ft_zero_flags_hexa(tab, ret, base);
	else if (tab->dash == 1)
	{
		ft_dash_flags_hexa(tab, ret, base);
		return (free(string));
	}
	ft_putnbr_base(tab, ret, base);
	free(string);
}
