/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:46:23 by asene             #+#    #+#             */
/*   Updated: 2024/11/21 15:25:10 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# define HEX_L "0123456789abcdef"
# define HEX_U "0123456789ABCDEF"

int		ft_printf(const char *format, ...);
char	*ft_printf_pointer(void *adress);
char	*ft_ulltoa(unsigned long long int n);
char	*ft_ulltoa_base(unsigned long long int n, char *base);
char	*ft_lltoa(long long int n);
char	*ft_lltoa_base(long long int n, char *base);

#endif