/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:46:49 by asene             #+#    #+#             */
/*   Updated: 2024/11/08 11:41:56 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_print_hex(n / 16, base);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_put_pointer(void *adress)
{
	if (adress == NULL)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (2 + ft_print_hex((unsigned long)adress, HEX_BASE_LOWER));
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

	count = 0;
	if (nb >= 10)
		count += ft_put_unsigned(nb / 10);
	count += ft_putchar(nb % 10 + '0');
	return (count);
}
