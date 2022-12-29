/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:55:29 by bgresse           #+#    #+#             */
/*   Updated: 2022/12/29 06:57:43 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar(char character, t_print *tab)
{
	tab->len += write(1, &character, 1);
}

void	ft_putstr(unsigned char *string, t_print *tab)
{
	size_t	index;

	index = 0;
	while (string[index])
		ft_putchar(string[index++], tab);
}

void	ft_print_char(t_print *tab)
{
	unsigned int	ret;
	unsigned char	*string;

	ret = va_arg(tab->args, unsigned int);
	string = ft_itoa(ret - '0');
	if (tab->point == 1 && tab->dash == 0)
		while (tab->precision-- > (int)ft_strlen((char *)string))
			ft_putchar(' ', tab);
	else if (tab->dash == 1)
	{
		printf("string = %s", string);
		ft_putchar(ret, tab);
		while (tab->precision-- > (int)ft_strlen((char *)string))
			ft_putchar(' ', tab);
		return (free(string));
	}
	else if (tab->precision)
		while (tab->precision-- > (int)ft_strlen((char *)string))
			ft_putchar(' ', tab);
	ft_putchar(ret, tab);
	free(string);
}
