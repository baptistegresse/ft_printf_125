/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:56:47 by bgresse           #+#    #+#             */
/*   Updated: 2022/12/29 00:47:23 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_string(t_print *tab)
{
	unsigned char	*ret;
	int				temp;
	
	temp = 0;
	ret = va_arg(tab->args, unsigned char *);
	if (!ret)
	{
		ft_putstr((unsigned char *)"(null)", tab);
		return ;
	}
	if (tab->point == 1 && tab->precision < (int)ft_strlen((char *)ret))
	{
		while (tab->precision--)
			ft_putchar(ret[temp++], tab);
		return ;
	}
	else if (tab->dash == 1 && tab->point == 0)
	{
		ft_putstr(ret, tab);
		while (tab->precision-- > (int)ft_strlen((char *)ret))
			ft_putchar(' ', tab);
		return ;
	}
	else if (tab->precision && tab->point == 0)
		while (tab->precision-- > (int)ft_strlen((char *)ret))
			ft_putchar(' ', tab);
	ft_putstr(ret, tab);
}
