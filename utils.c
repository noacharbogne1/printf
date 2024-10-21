/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:34:25 by ncharbog          #+#    #+#             */
/*   Updated: 2024/10/21 14:21:20 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_count(int nbr, char *base)
{
	int	count;
	int	i;

	i = 0;
	while (base[i])
		i++;
	count = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		count++;
	}
	while (nbr >= i)
	{
		nbr = nbr / i;
		count++;
	}
	return (count + 1);
}

int	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	nb;	
	int				i;
	unsigned int	len;

	i = 0;
	while (base[i])
		i++;
	len = i;
	i = 0;
	if (nbr < 0)
	{
		write (1, "-", 1);
		nb = (unsigned int) nbr * -1;
	}
	else
		nb = (unsigned int) nbr;
	if (nb >= len)
		ft_putnbr_base(nb / len, base);
	ft_putchar(base[nb % len]);
	i = ft_count(nbr, base);
	return (i);
}

int	ft_p(int f)
{
	unsigned long int	p;
	int	len;

	len = 0;
	p = (unsigned long int) f;
	ft_putstr("0x");
	len = ft_putnbr_base(p, "0123456789abcdef");
	return (len);
}

int	ft_putnbr_u(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
	{
		ft_putnbr_u(nb / 10);
		i++;
	}
	ft_putchar(nb % 10 + '0');
	i++;
	return (i);
}