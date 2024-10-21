/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:34:25 by ncharbog          #+#    #+#             */
/*   Updated: 2024/10/21 11:33:49 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	nb;	
	unsigned int	i;
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
	while (nb >= len)
	{
		nb = nb / len;
		ft_putchar(base[nb % len]);
	}
}

int	ft_p(int f)
{
	unsigned long int	p;

	p = (unsigned long int) f;
	ft_putchar("0x");
	ft_putnbr_base(p, "0123456789abcdef");
}

void	ft_putnbr_u(unsigned int nb)
{
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}