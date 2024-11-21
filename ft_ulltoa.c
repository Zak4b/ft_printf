/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:14:19 by asene             #+#    #+#             */
/*   Updated: 2024/11/21 16:17:35 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits_unsigned(unsigned long long n, char base_len)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*ft_ulltoa_base(unsigned long long int n, char *base)
{
	int		i;
	char	*result;
	int		base_len;

	base_len = ft_strlen(base);
	i = count_digits_unsigned(n, base_len);
	result = ft_calloc(i + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		result[--i] = base[n % base_len];
		n /= base_len;
	}
	return (result);
}

char	*ft_ulltoa(unsigned long long int n)
{
	return (ft_ulltoa_base(n, "0123456789"));
}
