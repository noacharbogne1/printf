/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:50:40 by ncharbog          #+#    #+#             */
/*   Updated: 2024/10/21 18:01:11 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_printf(char const *format, ...);
int		ft_putnbr_base(int nbr, char *base);
int		ft_count(int nbr, char *base);
int		ft_putnbr_u(long long nb);
int		ft_p(int f);

# endif