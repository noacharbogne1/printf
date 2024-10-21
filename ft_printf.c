/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:02:38 by ncharbog          #+#    #+#             */
/*   Updated: 2024/10/21 14:53:01 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_format(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (format == 'd' || format == 'i')
		return (ft_putnbr_base(va_arg(args, int), "0123456789"));
	if (format == 'x')
		return (ft_putnbr_base(va_arg(args, int), "0123456789abcdef"));
	if (format == 'X')
		return (ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF"));
	if (format == 'p')
		return (ft_p(va_arg(args, int)));
	if (format == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	return (0);
}

int	ft_printf(char const *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				ft_putchar(format[i]);
			else
				len += ft_format(format[i], args);
			i++;
		}
		ft_putchar(format[i]);
		i++;
	}
	va_end (args);
	return (len);
}

#include <stdio.h>

int main()
{
	int r = ft_printf("coucou %d\n", 1978000);
	ft_printf("%d\n", r);
	//printf("coucou %x\n", "jour");
}