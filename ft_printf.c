/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:02:38 by ncharbog          #+#    #+#             */
/*   Updated: 2024/10/21 11:32:36 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(char const *format, ...)
{
	int		i;
	int		f;
	char 	*s;
	va_list	args;

	i = 0;
	f = 0;
	s = NULL;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				ft_putchar(format[i]);
			if (format[i] == 'c')
			{
				f = (char) va_arg(args, int);
				ft_putchar(f);
			}
			if (format[i] == 's')
			{
				s = va_arg(args, char *);
				ft_putstr(s);
			}
			if (format[i] == 'd' || format[i] == 'i')
			{
				f = va_arg(args, int);
				ft_putnbr_base(f, "0123456789");
			}
			if (format[i] == 'x')
			{
				f = va_arg(args, int);
				ft_putnbr_base(f, "0123456789abcdef");
			}
			if (format[i] == 'X')
			{
				f = va_arg(args, int);
				ft_putnbr_base(f, "0123456789ABCDEF");
			}
			if (format[i] == 'p')
			{
				f = va_arg(args, int);
				ft_p(f);
			}
			if (format[i] == 'u')
			{
				f = va_arg(args, unsigned int);
				ft_putnbr_u(f);
			}
			i++;
		}
		ft_putchar(format[i]);
		i++;
	}
	va_end (args);
	return (1);
}

#include <stdio.h>

int main()
{
	ft_printf("cou%sou %s %s", 'c', "jjjj", "Lqurq");
}