/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:46:49 by asene             #+#    #+#             */
/*   Updated: 2024/11/21 15:26:21 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_pointer(void *adress)
{
	if (adress == NULL)
		return (ft_strdup("(nil)"));
	return (ft_strjoin("0x", ft_ulltoa_base((unsigned long)adress, HEX_L)));
}
