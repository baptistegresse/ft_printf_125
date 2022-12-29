/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:57:58 by bgresse           #+#    #+#             */
/*   Updated: 2022/12/29 06:33:11 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
#include <limits.h>

typedef struct s_print
{
	va_list	args;
	int		point;
	int		dash;
	int		precision;
	int		zero;
	int		len;
	int		plus;
	int		space;
	int		sharp;
	int		width;
}				t_print;

int		ft_printf(const char *format, ...)\
			__attribute__((format (printf, 1, 2)));

int		ft_get_precision(t_print *tab, const char *format, int index);
int		ft_format_flags(t_print *tab, const char *format, int index);
int		ft_format_eval(t_print *tab, const char *format, int index);

void	ft_putchar(char character, t_print *tab);
void	ft_putstr(unsigned char *string, t_print *tab);
void	ft_putnbr(int number, t_print *tab);
void	ft_putnbr_base(t_print *tab, unsigned int number, char *base);

void	ft_print_char(t_print *tab);
void	ft_print_string(t_print *tab);
void	ft_print_number(t_print *tab);
void	ft_print_hexa(t_print *tab, char *base);
void    ft_print_adress(t_print *tab);

unsigned char	*ft_uitoh(unsigned int nb);

#endif