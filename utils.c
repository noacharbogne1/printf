/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:34:25 by ncharbog          #+#    #+#             */
/*   Updated: 2024/10/21 18:21:06 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	long long int	nb;
	int				i;
	int				len;

	i = 0;
	while (base[i])
		i++;
	len = ft_count(nbr, base);
	if (nbr < 0)
	{
		write (1, "-", 1);
		nb = (long long int) nbr * -1;
	}
	else
		nb = (long long int) nbr;
	if (nb >= i)
		ft_putnbr_base(nb / i, base);
	ft_putchar(base[nb % i]);
	return (len);
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

int	ft_putnbr_u(long long nb)
{
	unsigned int	len;

	nbr = 0;
	if (nb < 0)
		nb = UINT_MAX - (-nb) + 1;
	len = ft_count(nbr, "0123456789");
	if (nb > 9)
	{
		ft_putnbr_u(nb / 10);
	}
	ft_putchar(nb % 10 + '0');
	return (len);
}