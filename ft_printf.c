/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:02:38 by ncharbog          #+#    #+#             */
/*   Updated: 2024/10/18 11:42:13 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(char const *format, ...)
{
	int		i;
	int		c;
	va_list	args;
	char	*dest;

	i = 0;
	args = 0;
	c = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			i++;
			if (format[i] == '%')
			{
				dest = ft_strdup("%");
				ft_putstr(dest);
			}
			if (format[i] == 'c')
				int c = va_arg(args, int);
				ft_format_char(format[i], c);
			i++;
		ft_putchar(&format[i]);
		i++;
	}
	va_end (args);
}