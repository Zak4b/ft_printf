/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:46:49 by asene             #+#    #+#             */
/*   Updated: 2024/11/07 20:14:39 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_lower(long n)
{
	int			count;
	static char	*hex = "0123456789abcdef";

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 16)
		count += ft_print_hex_lower(n / 16);
	count += ft_putchar(hex[n % 16]);
	return (count);
}
int	ft_print_hex_upper(long n)
{
	int			count;
	static char	*hex = "0123456789ABCDEF";

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 16)
		count += ft_print_hex_upper(n / 16);
	count += ft_putchar(hex[n % 16]);
	return (count);
}

int	ft_put_pointer(void *adress)
{
	ft_putstr("0x");
	return (2 + ft_print_hex_lower((long)adress));
}

int	ft_putnbr(int nb)
{
	int		count;
	long	nbr;

	count = 0;
	nbr = nb;
	if (nbr < 0)
	{
		count += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar(nbr % 10 + '0');
	return (count);
}

int	ft_put_unsigned(unsigned int nb)
{
	int				count;
	unsigned long	nbr;

	count = 0;
	nbr = nb;
	if (nbr >= 10)
		count += ft_put_unsigned(nbr / 10);
	count += ft_putchar(nbr % 10 + '0');
	return (count);
}