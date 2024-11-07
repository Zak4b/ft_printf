#include "ft_printf.h"

// cspdiuxX%
static int	handle_conversion(char **str, va_list args)
{
	(*str)++;
	//handle_flags();
	if (**str == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (**str == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (**str == 'p')
		// hex pointer
	else if (**str == 'd' || **str == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (**str == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (**str == 'x')
		// hex lower
	else if (**str == 'X')
		// hex upper
	else if (**str == '%')
		ft_putchar_fd('%', 1);
	else
		//erreur format
	(*str)++;
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		char_count;
	va_list	args;

	char_count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			handle_conversion((char **)&format, args);
		else
			ft_putchar_fd(*(format++), 1);
	}
	va_end(args);
	return (char_count);
}