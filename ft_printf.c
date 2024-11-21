/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:19:56 by asene             #+#    #+#             */
/*   Updated: 2024/11/21 16:13:10 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*handle_conversion(char **str, va_list args)
{
	char	*result;

	(*str)++;
	if (**str == 'c')
		result = ft_strdup("CHAR");
	else if (**str == 's')
		result = ft_strdup(va_arg(args, char *));
	else if (**str == 'p')
		result = ft_printf_pointer(va_arg(args, void *));
	else if (**str == 'd' || **str == 'i')
		result = ft_itoa(va_arg(args, int));
	else if (**str == 'u')
		result = ft_ulltoa((int)va_arg(args, unsigned int));
	else if (**str == 'x')
		result = ft_ulltoa_base(va_arg(args, unsigned int), HEX_L);
	else if (**str == 'X')
		result = ft_ulltoa_base(va_arg(args, unsigned int), HEX_U);
	else
		result = ft_strdup("%");
	(*str)++;
	return (result);
}

static t_list	*ft_printf_va(const char *s, va_list args)
{
	t_list	*string_lst;
	t_list	*a;

	string_lst = NULL;
	while (*s)
	{
		if (*s == '%' && *(s + 1) && ft_strchr("cspdiuxX%", *(s + 1)))
		{
			ft_lstadd_back(&string_lst, ft_lstnew(handle_conversion((char **)&s, args)));
			a = ft_lstlast(string_lst);
			ft_lstadd_front(&a, ft_lstnew(ft_strdup("0000000")));
		}
		else
			ft_putchar_fd(1, *(s++));
	}
	return (string_lst);
}

void	f(void *string)
{
	ft_putstr_fd((char *)string, 1);
}

int	ft_printf(const char *format, ...)
{
	int		char_count;
	t_list	*string_lst;
	va_list	args;

	char_count = 0;
	va_start(args, format);
	string_lst = ft_printf_va(format, args);
	va_end(args);
	ft_lstiter(string_lst, f);
	ft_lstclear(&string_lst, free);
	return (char_count);
}
