/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:02:38 by ncharbog          #+#    #+#             */
/*   Updated: 2024/10/18 15:13:29 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void	ft_format_char(int c)
{
	char	a;
	
	a = (char)c;
	if (a)
		write(1, &a, 1);
}

void	ft_format_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_printf(char const *format, ...)
{
	int		i;
	int		c;
	char 	*s;
	va_list	args;

	i = 0;
	c = 0;
	s = NULL;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				write(1, &format[i], 1);
			if (format[i] == 'c')
			{
				c = va_arg(args, int);
				ft_format_char(c);
			}
			if (format[i] == 's')
			{
				s = va_arg(args, char *);
				ft_format_str(s);
			}
			i++;
		}
		write(1, &format[i], 1);
		i++;
	}
	va_end (args);
	return (1);
}

int main()
{
	ft_printf("cou%cou %s %s", 'c', "jjjj", "Lqurq");
}