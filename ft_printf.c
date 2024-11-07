/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:19:56 by asene             #+#    #+#             */
/*   Updated: 2024/11/07 20:13:28 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// cspdiuxX%
static int	is_conversion(char c)
{
	const char	*specifiers;
	int			i;

	specifiers = "cspdiuxX%";
	i = 0;
	while (specifiers[i])
	{
		if (c == specifiers[i])
			return (1);
		i++;
	}
	return (0);
}
static int	handle_conversion(char **str, va_list args)
{
	int	count;

	count = 0;
	(*str)++;
	if (**str == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (**str == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (**str == 'p')
		count = ft_put_pointer(va_arg(args, void *));
	else if (**str == 'd' || **str == 'i')
		count = ft_putnbr(va_arg(args, int));
	else if (**str == 'u')
		count = ft_putnbr((int)va_arg(args, unsigned int));
	else if (**str == 'x')
		count = ft_print_hex_lower(va_arg(args, int));
	else if (**str == 'X')
		count = ft_print_hex_upper(va_arg(args, int));
	else if (**str == '%')
		count = ft_putchar('%');
	(*str)++;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		char_count;
	va_list	args;

	char_count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) && is_conversion(*(format + 1)))
			char_count += handle_conversion((char **)&format, args);
		else
			char_count += ft_putchar(*(format++));
	}
	va_end(args);
	return (char_count);
}
